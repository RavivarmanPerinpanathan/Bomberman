#ifndef __BOMB_HH_
# define __BOMB_HH_

#include <iostream>
#include <string>

class Bomb
{
public:
  Bomb();
  ~Bomb();
  Bomb(Bomb const &);
  Bomb &operator=(Bomb const &);
};

#endif /* !__BOMB_HH__ */
