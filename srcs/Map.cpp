#include <cstdio>
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

std::vector<std::pair<int, int> >		&Map::getTmpMap()
{
  return (_tmpMap);
}

void		Map::setBox(int h, int w, status stat)
{
  getMap()[std::make_pair(h, w)] = stat;
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

void		Map::setPlayersMap(std::vector<Player> players)
{
  std::pair<int, int>	p;
  int			cornerX;
  int			cornerY;
  status		who;

  who = P1;
  srand(time(NULL));
  cornerX = 1 + (-2 * (rand() % 2));
  cornerY = 1 + (-2 * (rand() % 2));
  for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it)
    {
      if (players.begin() != it)
	{
	  who = P2;
	  cornerX = -1 * cornerX;
	  cornerY = -1 * cornerY;
	}
      p.second = (cornerX * (rand() % (getWidth()/10)+2)) + (((cornerX * -1)+1) * (getWidth()/2));
      p.first = (cornerY * (rand() % (getHeight()/10)+2)) + (((cornerY * -1)+1) * (getHeight()/2));
      setBox(p.first, p.second, who);
      it->setPos(p);
      popTmpMap(p);
      createL(p);
    }
}

void		Map::setBotsMap(std::vector<Bot> bots)
{
  std::pair<int, int>	p;

  srand(time(NULL));
  for (std::vector<Bot>::iterator it = bots.begin(); it != bots.end(); ++it)
    {
      while (checkIfCharacter(p = getTmpMap()[rand() % getTmpMap().size()], P1) == 0
	     || checkIfCharacter(p, P2) == 0 || checkIfCharacter(p, BOT) == 0)
	;
      setBox(p.first, p.second, BOT);
      it->setPos(p);
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
      setBox(p.first, p.second, block);
      popTmpMap(p);
    }
}

int		Map::setRandomMap(std::vector<Player> players, std::vector<Bot> bots)
{
  for (int h = 0; h < getHeight(); ++h)
    {
      for (int w = 0; w < getWidth(); ++w)
  	{
  	  if (h == 0 || h == getHeight() - 1
  	      || w == 0 || w == getWidth() - 1)
	    setBox(h, w, SOLID);
	  else
	    {
	      setBox(h, w, EMPTY);
	      getTmpMap().push_back(std::make_pair(h, w));
	    }
  	}
    }
  if (getTmpMap().size() < ((players.size() * 5) + (bots.size() * 5)))
    return (1);
  setPlayersMap(players);
  setBotsMap(bots);
  setBlockMap(5, SOLID);
  setBlockMap(80, BREAK);
  return (0);
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
      else if(it->second == RANGE)
	printf("\33[32m");
      else if(it->second == SIMULT)
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
