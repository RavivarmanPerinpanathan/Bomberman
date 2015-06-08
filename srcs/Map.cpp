#include "Map.hh"

Map::Map(int width, int height)
  : _width(width), _height(height)
{

}

Map::~Map()
{

}

Map::Map(Map const &c)
  : _width(c._width), _height(c._height)
{

}

Map		&Map::operator=(Map const &c)
{
  if (this != &c)
    {
      _width = c._width;
      _height = c._height;
    }
  return (*this);
}

int		Map::getWidth() const
{
  return (_width);
}

int		Map::getHeight() const
{
  return (_height);
}

std::map<std::pair<int, int>, Map::status>	&Map::getMap()
{
  return (_map);
}

void		Map::setBox(int h, int w, status stat)
{
  getMap()[std::make_pair(h, w)] = stat;
}

void		Map::setPlayersMap(std::vector<Player> players)
{
  /* check si assez de place pour nombre de players */
  srand(time(NULL));
  (void)players;
}

void		Map::setBotsMap(std::vector<Bot> bots)
{
  /* check si assez de place pour nombre de bots */
  srand(time(NULL));
  for (std::vector<Bot>::iterator it = bots.begin(); it != bots.end(); ++it)
    {
      it->setPos(std::make_pair(rand() % getHeight(), rand() % getWidth()));
      while (getMap()[it->getPos()] != EMPTY || checkIfCharacter(it->getPos(), P1) == 0
	     || checkIfCharacter(it->getPos(), P2) == 0)
	it->setPos(std::make_pair(rand() % getHeight(), rand() % getWidth()));
      getMap()[it->getPos()] = BOT;
    }
}

void		Map::setRandomMap(std::vector<Player> players, std::vector<Bot> bots)
{
  for (int h = 0; h < getHeight(); ++h)
    {
      for (int w = 0; w < getWidth(); ++w)
  	{
  	  if (h == 0 || h == getHeight() - 1
  	      || w == 0 || w == getWidth() - 1)
	    setBox(h, w, SOLID);
	  else
	    setBox(h, w, EMPTY);
  	}
    }
  setPlayersMap(players);
  setBotsMap(bots);
}

int		Map::checkIfCharacter(std::pair<int, int> pos, status character)
{
  if (getMap()[std::make_pair(pos.first + 1, pos.second)] == character
      || getMap()[std::make_pair(pos.first - 1, pos.second)] == character
      || getMap()[std::make_pair(pos.first, pos.second + 1)] == character
      || getMap()[std::make_pair(pos.first, pos.second - 1)] == character)
    return (0);
  return (1);
}

void		Map::showMap()
{
  for (std::map<std::pair<int, int>, status>::iterator it = getMap().begin(); it != getMap().end(); ++it)
    {
      std::cout << it->second;
      if (it->first.second == getWidth() - 1)
	std::cout << std::endl;
    }
}
