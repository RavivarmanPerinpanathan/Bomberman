#include <cstdio>
#include "Map.hh"

Map::Map()
{

}

Map::~Map()
{

}

Map::Map(Map const &c)
  : _width(c._width), _height(c._height), _map(c._map), _players(c._players), _bots(c._bots)
{

}

Map		&Map::operator=(Map const &c)
{
  if (this != &c)
    {
      _width = c._width;
      _height = c._height;
      _players = c._players;
      _bots = c._bots;
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

std::vector<Player>				&Map::getPlayers()
{
  return (_players);
}

void		Map::setPlayers(std::string const &p1, std::string const &p2)
{
  if (!p1.empty())
    {
      if (!p2.empty())
	_players.push_back(Player(p2));
      _players.push_back(Player(p1));
    }
}

std::vector<Bot>				&Map::getBots()
{
  return (_bots);
}

void						Map::setBots(int bots)
{
  for (int i = 0; i < bots; ++i)
    _bots.push_back(Bot());
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

void		Map::setRandomMap()
{
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
  for (std::vector<Player>::iterator it = getPlayers().begin(); it != getPlayers().end(); ++it)
    {
      if (getPlayers().begin() != it)
	{
	  who = P2;
	  cornerX = -1 * cornerX;
	  cornerY = -1 * cornerY;
	}
      p.second = (cornerX * (rand() % (getWidth()/10)+2)) + (((cornerX * -1)+1) * (getWidth()/2));
      p.first = (cornerY * (rand() % (getHeight()/10)+2)) + (((cornerY * -1)+1) * (getHeight()/2));
      setBox(std::make_pair(p.first, p.second), who);
      it->setPos(p);
      popTmpMap(p);
      createL(p);
    }
}

void		Map::setBotsMap()
{
  std::pair<int, int>	p;

  srand(time(NULL));
  for (std::vector<Bot>::iterator it = getBots().begin(); it != getBots().end(); ++it)
    {
      while (checkIfCharacter(p = getTmpMap()[rand() % getTmpMap().size()], P1) == 0
	     || checkIfCharacter(p, P2) == 0 || checkIfCharacter(p, BOT) == 0)
	;
      setBox(std::make_pair(p.first, p.second), BOT);
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

void		Map::updateMap(int idx, std::pair<int, int> curPos, std::pair<int, int> newPos)
{
  newPos.first = curPos.first + newPos.first;
  newPos.second = curPos.second + newPos.second;
  if (getMap()[newPos] == EMPTY || getMap()[newPos] == BONUS)
    {
      if (idx == 3)
	;
      else
	{
	  usleep(getPlayers()[idx].getSpeed());
	  getPlayers()[idx].setPos(newPos);
	}
      setBox(newPos, getMap()[curPos]);
      setBox(curPos, EMPTY);
    }
  showMap();
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
      else if(it->second == BONUS)
	printf("\33[32m");
      else if(it->second == SOLID)
	printf("\33[30m");
      else if(it->second == BREAK)
	printf("\33[33m");
      else if(it->second == DROP)
	printf("\33[37m");
      std::cout << it->second;
      if (it->first.second == getWidth() - 1)
	std::cout << std::endl;
      printf("\33[0m");
    }
}
