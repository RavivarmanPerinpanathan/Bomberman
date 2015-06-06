#ifndef __MAP_HH__
# define __MAP_HH__

#include <iostream>
#include <string>
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

  Map(int, int);
  ~Map();
  Map(Map const &);
  Map &operator=(Map const &);

  int					getWidth() const;
  int					getHeight() const;
  std::map<std::pair<int, int>, status>	&getMap();

private:
  int					_width;
  int					_height;
  std::map<std::pair<int, int>, status> _map;
};

#endif /* !__MAP_HH__ */
