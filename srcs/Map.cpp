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

void		Map::setPlayersMap(std::vector<Player> players, std::vector<std::pair<int, int> > tmpMap)
{
  int		cornerX;
  int		cornerY;
  int		playerX;
  int		playerY;


  /* check si assez de place pour nombre de players */
  srand(time(NULL));
  cornerX = 1 + (-2 * (rand() % 2));
  cornerY = 1 + (-2 * (rand() % 2));
  playerX = (cornerX * (rand() % (getWidth() / 10) + 2)) + (((cornerX * -1) + 1) * (getWidth() / 2));
  playerY = (cornerY * (rand() % (getHeight() / 10) + 2)) + (((cornerY * -1) + 1) * (getHeight() / 2));
  for (std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it)
    {
      if (players.begin() != it)
	{
	  cornerX = -1 * cornerX;
	  cornerY = -1 * cornerY;
	  playerX = (cornerX * (rand() % (getWidth() / 10) + 2)) + (((cornerX * -1) + 1) * (getWidth() / 2));
	  playerY = (cornerY * (rand() % (getHeight() / 10) + 2)) + (((cornerY * -1) + 1) * (getHeight() / 2));
	  setBox(playerY, playerX, P2);
	}
      else
	{
	  setBox(playerY, playerX, P1);
	}
      // std::vector<std::pair<int, int> > pd;
      // pd.push_back(std::make_pair(1, 1));
      // std::pair<int, int> ok = std::make_pair(1, 1);
      // std::cout << tmpMap[(playerY * playerX)].first << std::endl;
      // std::cout << getMap()[std::make_pair(1, 1)] << std::endl;
      // std::cout << std::find(tmpMap.begin(), tmpMap.end(), tmpMap[(ok.first, ok.second)]) << std::endl;
      // for (std::vector<std::pair<int, int> >::iterator vp = tmpMap.begin(); vp != tmpMap.end(); ++vp)
      // 	{
      // 	  if (vp->first == playerY && vp->second == playerX)
      // 	    {
      // 	      std::cout << "BAH OUAI" << std::endl;
      // 	    }

      // 	}
      // if (std::find(tmpMap.begin(), tmpMap.end(), tmpMapstd::make_pair(playerY, playerX)))
      // 	{
      // 	  std::cout << "aa" << std::endl;
      // 	}
      (void)tmpMap;
      // (void)playerX;
      // (void)playerY;
      it->setPos(std::make_pair(playerY, playerX));
      // tmpMap[std::make_pair(0, 0)] = 0;
      // std::cout << tmpMap.at(std::make_pair(0, 0)) << std::endl;
      // tmpMap.erase(tmpMap[std::find(tmpMap.begin(), tmpMap.end(), std::make_pair(playerY, playerX))]);
      // for (std::vector<std::pair<int, int> >::iterator it = tmpMap.begin(); it != tmpMap.end(); ++it)
      // 	if ((*it) == ' ' || (*it) == '\t')
      // 	  it = _line.erase(--it);

      // tmpMap.erase(std::remove(tmpMap.begin(), tmpMap.end(),
      // 			       std::make_pair(playerY, playerX)), tmpMap.end());
    }
}

void		Map::setBotsMap(std::vector<Bot> bots)
{
  /* check si assez de place pour nombre de bots */
  (void)bots;
  // srand(time(NULL));
  // for (std::vector<Bot>::iterator it = bots.begin(); it != bots.end(); ++it)
  //   {
  //     it->setPos(std::make_pair(rand() % getHeight(), rand() % getWidth()));
  //     while (getMap()[it->getPos()] != EMPTY || checkIfCharacter(it->getPos(), P1) == 0
  // 	     || checkIfCharacter(it->getPos(), P2) == 0)
  // 	it->setPos(std::make_pair(rand() % getHeight(), rand() % getWidth()));
  //     getMap()[it->getPos()] = BOT;
  //   }
}

void		Map::setRandomMap(std::vector<Player> players, std::vector<Bot> bots)
{
  std::vector<std::pair<int, int> > tmpMap;

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
	      tmpMap.push_back(std::make_pair(h, w));
	    }
  	}
    }
  setPlayersMap(players, tmpMap);
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
