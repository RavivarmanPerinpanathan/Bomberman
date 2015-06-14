#include "AObject.hh"

AObject::AObject()
  : _position(0, 0, 0), _rotation(0, 0, 0), _scale(20, 20, 1)
{

}

AObject::~AObject()
{

}

int			AObject::getId() const
{
  return (_id);
}

void			AObject::setId(int id)
{
  _id = id;
}

std::pair<int, int>	AObject::getPos() const
{
  return (_pos);
}

void			AObject::setPos(std::pair<int, int> pos)
{
  _pos = pos;
}

Map			*AObject::getMap()
{
  return (_map);
}

void			AObject::setMap(Map *map)
{
  _map = map;
}

void		AObject::updateMap(std::pair<int, int> curPos, std::pair<int, int> newPos)
{
  newPos.first = curPos.first + newPos.first;
  newPos.second = curPos.second + newPos.second;
  if (getMap()->getMap()[newPos] == Map::EMPTY || getMap()->getMap()[newPos] == Map::RANGE
      || getMap()->getMap()[newPos] == Map::SIMULT || getMap()->getMap()[newPos] == Map::SPEED)
    {
      setPos(newPos);
      getMap()->setBox(newPos, getMap()->getMap()[curPos]);
      getMap()->setBox(curPos, Map::EMPTY);
      _time = 0;
    }
}

void AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4 AObject::getTransformation()
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
