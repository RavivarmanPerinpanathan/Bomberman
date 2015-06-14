#include <cstdio>
#include "Map.hh"

Map::Map(int width, int height, int nbPlayers, int nbBots)
  : _width(width), _height(height), _nbPlayers(nbPlayers), _nbBots(nbBots)
{

}

Map::~Map()
{

}

Map::Map(Map const &c)
  : _width(c._width), _height(c._height), _nbPlayers(c._nbPlayers), _nbBots(c._nbBots), _map(c._map)
{

}

Map		&Map::operator=(Map const &c)
{
  if (this != &c)
    {
      _width = c._width;
      _height = c._height;
      _nbPlayers = c._nbPlayers;
      _nbBots = c._nbBots;
      _map = c._map;
    }
  return (*this);
}

int		Map::getWidth() const
{
  return (_width);
}

void		Map::setWidth(int width)
{
  _width = width;
}

int		Map::getHeight() const
{
  return (_height);
}

void		Map::setHeight(int height)
{
  _height = height;
}

int		Map::getNbPlayers() const
{
  return (_nbPlayers);
}

void		Map::setNbPlayers(int nbPlayers)
{
  _nbPlayers = nbPlayers;
}

int		Map::getNbBots() const
{
  return (_nbBots);
}

void		Map::setNbBots(int nbBots)
{
  _nbBots = nbBots;
}

std::map<std::pair<int, int>, Map::status>	&Map::getMap()
{
  return (_map);
}

std::vector<std::pair<int, int> >		&Map::getTmpMap()
{
  return (_tmpMap);
}

void		Map::setBox(std::pair<int, int> pos, status stat)
{
  getMap()[pos] = stat;
}

void		Map::setTmpBox(std::pair<int, int> pos)
{
  getTmpMap().push_back(pos);
}

int		Map::setRandomMap()
{
  unsigned int	min = 5;
  for (int h = 0; h < getHeight(); ++h)
    {
      for (int w = 0; w < getWidth(); ++w)
  	{
  	  if (h == 0 || h == getHeight() - 1
  	      || w == 0 || w == getWidth() - 1)
	    setBox(std::make_pair(h, w), SOLID);
	  else
	    {
	      setBox(std::make_pair(h, w), EMPTY);
	      setTmpBox(std::make_pair(h, w));
	    }
  	}
    }
  if (getTmpMap().size() < ((getNbPlayers() * min) + (getNbBots() * min)))
    return (1);
  setPlayersMap();
  setBotsMap();
  setBlockMap(5, Map::SOLID);
  setBlockMap(10, Map::BREAK);
  std::cout << _nbPlayers << std::endl;
  return (0);
}

void		Map::setPlayersMap()
{
  std::pair<int, int>	p;
  int			cornerX;
  int			cornerY;
  status		who;

  who = P1;
  srand(time(NULL));
  cornerX = 1 + (-2 * (rand() % 2));
  cornerY = 1 + (-2 * (rand() % 2));
  for (int i = 0; i < getNbPlayers(); ++i)
    {
      if (i == 1)
	{
	  who = P2;
	  cornerX = -1 * cornerX;
	  cornerY = -1 * cornerY;
	}
      p.second = (cornerX * (rand() % (getWidth()/10)+2)) + (((cornerX * -1)+1) * (getWidth()/2));
      p.first = (cornerY * (rand() % (getHeight()/10)+2)) + (((cornerY * -1)+1) * (getHeight()/2));
      setBox(std::make_pair(p.first, p.second), who);
      popTmpMap(p);
      createL(p);
    }
}

void		Map::setBotsMap()
{
  std::pair<int, int>	p;

  srand(time(NULL));
  for (int i = 0; i < getNbBots(); ++i)
    {
      while (checkIfCharacter(p = getTmpMap()[rand() % getTmpMap().size()], P1) == 0
	     || checkIfCharacter(p, P2) == 0 || checkIfCharacter(p, BOT) == 0)
	;
      setBox(std::make_pair(p.first, p.second), BOT);
      popTmpMap(p);
      createL(p);
    }
}

void		Map::setBlockMap(int percent, status block)
{
  std::pair<int, int>	p;
  int			nb;

  nb = (percent * getTmpMap().size()) / 100;
  for(int i = 0; i < nb; ++i)
    {
      p = getTmpMap()[rand() % getTmpMap().size()];
      setBox(std::make_pair(p.first, p.second), block);
      popTmpMap(p);
    }
}

void		Map::popTmpMap(std::pair<int, int> elem)
{
  for (std::vector<std::pair<int, int> >::iterator it = getTmpMap().begin(); it != getTmpMap().end(); ++it)
    if (it->first == elem.first && it->second == elem.second)
      {
	it = getTmpMap().erase(it);
	break;
      }
}

void		Map::createL(std::pair<int, int> elem)
{
  int		x;
  int		y;

  x = 1 + (-2 * (rand() % 2));
  y = 1 + (-2 * (rand() % 2));
  if (getMap()[std::make_pair(elem.first, elem.second + x)] == EMPTY)
    {
      popTmpMap(std::make_pair(elem.first, elem.second + x));
      if (getMap()[std::make_pair(elem.first + y, elem.second)] == EMPTY)
	popTmpMap(std::make_pair(elem.first + y, elem.second));
      else
	popTmpMap(std::make_pair(elem.first - y, elem.second));
    }
  else
    {
      popTmpMap(std::make_pair(elem.first, elem.second - x));
      if (getMap()[std::make_pair(elem.first + y, elem.second)] == EMPTY)
	popTmpMap(std::make_pair(elem.first + y, elem.second));
      else
	popTmpMap(std::make_pair(elem.first - y, elem.second));
    }
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
  std::cout << "in map" << std::endl;
  for (std::map<std::pair<int, int>, status>::iterator it = getMap().begin(); it != getMap().end(); ++it)
    {
      if (it->second == P1)
	printf("\33[34m");
      else if(it->second == P2)
	printf("\33[36m");
      else if(it->second == BOT)
	printf("\33[31m");
      else if(it->second == BOMB)
	printf("\33[35m");
      else if(it->second == SPEED)
	printf("\33[32m");
      else if(it->second == SIMULT)
	printf("\33[32m");
      else if(it->second == RANGE)
	printf("\33[32m");
      else if(it->second == SOLID)
	printf("\33[30m");
      else if(it->second == BREAK)
	printf("\33[33m");
      std::cout << it->second;
      if (it->first.second == getWidth() - 1)
	std::cout << std::endl;
      printf("\33[0m");
    }
}
