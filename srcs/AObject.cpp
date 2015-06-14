#include "Bomb.hh"
#include "AObject.hh"

AObject::AObject()
  : _position(0, 0, 0), _rotation(0, 0, 0), _scale(20, 20, 1)
{

}

AObject::~AObject()
{

}

Map::status		AObject::getMapEnum() const
{
  return (_mapEnum);
}

void			AObject::setMapEnum(Map::status mapEnum)
{
  _mapEnum = mapEnum;
}

std::pair<int, int>	AObject::getPos() const
{
  return (_pos);
}

void			AObject::setPos(std::pair<int, int> pos)
{
  _pos = pos;
}

float			AObject::getSpeed() const
{
  return (_speed);
}

void			AObject::setSpeed(float speed)
{
  _speed = speed;
}

int			AObject::getSimult() const
{
  return (_simult);
}

void			AObject::setSimult(int simult)
{
  _simult = simult;
}

int			AObject::getRange() const
{
  return (_range);
}

void			AObject::setRange(int range)
{
  _range = range;
}

Map			*AObject::getMap()
{
  return (_map);
}

void			AObject::setMap(Map *map)
{
  _map = map;
}

bool			AObject::dropBomb()
{
  std::cout << "simult = " << getSimult() << std::endl;;
  if (_simult > 0)
    {
      AObject *bomb;

      bomb = new Bomb();
      if (bomb->initialize() == false)
  	return false;
      bomb->setPos(getPos());
      bomb->setRange(getRange());
      getMap()->setBox(bomb->getPos(), Map::BOMB);
      _bomb.push_back(bomb);
      setSimult(getSimult() - 1);
      _time = 0;
    }
  return true;
}

bool			AObject::bombAround(int x, int y, AObject *bomb)
{
  std::pair<int, int>	around;

  for (int i = 0; i < getRange(); ++i)
    {
      around = std::make_pair(bomb->getPos().first + (x * i), bomb->getPos().second + (y * i));
      if (getMap()->getMap()[around] != Map::SOLID)
	{
	  // draw ici //
	  if (getMap()->getMap()[around] == Map::BREAK)
	    {
	      if (rand() % 2 == 0)
		getMap()->setBox(around, static_cast<Map::status>(Map::SPEED + rand() % 3));
	      return true;
	    }
	  getMap()->setBox(around, Map::EMPTY);
	}
      else
	return false;
    }
  return true;
}

void			AObject::updateBomb(int it, AObject *bomb)
{
  _bomb.erase(_bomb.begin()+it);
  bombAround(0, 1, bomb);
  bombAround(1, 0, bomb);
  bombAround(0, -1, bomb);
  bombAround(-1, 0, bomb);
  getMap()->setBox(bomb->getPos(), Map::EMPTY);
  setSimult(getSimult() + 1);
}

void			AObject::updateStat(Map::status status)
{
  if (status == Map::SPEED)
    if (getSpeed() > 0.5f)
      setSpeed(getSpeed() - 0.01f);
  if (status == Map::SIMULT)
    setSimult(getSimult() + 1);
  if (status == Map::RANGE)
    setRange(getRange() + 1);
}

void			AObject::updateMap(std::pair<int, int> curPos, std::pair<int, int> newPos)
{
  newPos.first = curPos.first + newPos.first;
  newPos.second = curPos.second + newPos.second;
  // for (std::vector<AObject *>::iterator it = _bomb.begin(); it != _bomb.end(); ++it)
  //   getMap()->setBox((*it)->getPos(), Map::BOMB);
  if (getMap()->getMap()[newPos] == Map::EMPTY || getMap()->getMap()[newPos] == Map::RANGE
      || getMap()->getMap()[newPos] == Map::SIMULT || getMap()->getMap()[newPos] == Map::SPEED)
    {
      if (getMap()->getMap()[newPos] != Map::EMPTY)
	updateStat(getMap()->getMap()[newPos]);
      setPos(newPos);
      getMap()->setBox(newPos, getMapEnum());
      getMap()->setBox(curPos, Map::EMPTY);
      _time = 0;
    }
  getMap()->showMap();
}

void			AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void			AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void			AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4		AObject::getTransformation()
{
  glm::mat4 transform(1); // On cree une matrice identite
  // On applique ensuite les rotations selon les axes x, y et z
  /*  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  // On effectue ensuite la translation
  transform = glm::translate(transform, _position);
  // Et pour finir, on fait la mise a l'echelle*/
  transform = glm::scale(transform, _scale);
  return (transform);
}
