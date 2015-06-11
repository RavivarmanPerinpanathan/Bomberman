#ifndef __MAP_HH__
# define __MAP_HH__

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "Player.hh"
#include "Bot.hh"

#define	VIEWPORT_X	20
#define	VIEWPORT_Y	20

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

  Map(int, int);
  ~Map();
  Map(Map const &);
  Map &operator=(Map const &);

  int					getWidth() const;
  int					getHeight() const;
  std::map<std::pair<int, int>, status>	&getMap();
  std::vector<std::pair<int, int> >	&getTmpMap();
  void					setBox(int, int, status);

  void					createL(std::pair<int, int>);
  void					popTmpMap(std::pair<int, int>);
  void					setPlayersMap(std::vector<Player>);
  void					setBotsMap(std::vector<Bot>);
  void					setBlockMap(int, status);
  int					setRandomMap(std::vector<Player>, std::vector<Bot>);
  int				        checkIfCharacter(std::pair<int, int>, status);
  void					showMap();

private:
  int					_width;
  int					_height;
  std::vector<std::pair<int, int> >	_tmpMap;
  std::map<std::pair<int, int>, status> _map;
};

#endif /* !__MAP_HH__ */
