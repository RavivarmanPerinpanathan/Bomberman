#ifndef __MAP_HH__
# define __MAP_HH__

#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <vector>
#include <map>

class Map
{
public:
  enum status
    {
      EMPTY,
      SOLID,
      BREAK,
      BOMB,
      SPEED,
      RANGE,
      SIMULT,
      P1,
      P2,
      BOT
    };

  Map(int, int, int, int);
  ~Map();
  Map(Map const &);
  Map &operator=(Map const &);

  int					getWidth() const;
  void					setWidth(int);
  int					getHeight() const;
  void					setHeight(int);
  int					getNbPlayers() const;
  void					setNbPlayers(int);
  int					getNbBots() const;
  void					setNbBots(int);
  std::map<std::pair<int, int>, status>	&getMap();
  std::vector<std::pair<int, int> >	&getTmpMap();

  int					setRandomMap();
  void					setBox(std::pair<int, int>, status);
  void					setTmpBox(std::pair<int, int>);
  void					setPlayersMap();
  void					setBotsMap();
  void					setBlockMap(int, status);
  void					createL(std::pair<int, int>);
  void					popTmpMap(std::pair<int, int>);
  int				        checkIfCharacter(std::pair<int, int>, status);
  void					updateMap(int, std::pair<int, int>, std::pair<int, int>);
  void					showMap();

protected:
  int					_width;
  int					_height;
  int					_nbPlayers;
  int					_nbBots;
  std::map<std::pair<int, int>, status> _map;
  std::vector<std::pair<int, int> >	_tmpMap;
};

#endif /* !__MAP_HH__ */
