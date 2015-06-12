#ifndef __MAP_HH__
# define __MAP_HH__

#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
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
      BONUS,
      P1,
      P2,
      BOT,
      DROP
    };

  Map();
  ~Map();
  Map(Map const &);
  Map &operator=(Map const &);

  int					getWidth() const;
  void					setWidth(int);
  int					getHeight() const;
  void					setHeight(int);
  std::vector<Player>			&getPlayers();
  void					setPlayers(std::string const &, std::string const &);
  std::vector<Bot>			&getBots();
  void					setBots(int);
  std::map<std::pair<int, int>, status>	&getMap();
  std::vector<std::pair<int, int> >	&getTmpMap();

  void					setRandomMap();
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
  std::map<std::pair<int, int>, status> _map;
  std::vector<Player>			_players;
  std::vector<Bot>			_bots;
  std::vector<std::pair<int, int> >	_tmpMap;
};

#endif /* !__MAP_HH__ */
