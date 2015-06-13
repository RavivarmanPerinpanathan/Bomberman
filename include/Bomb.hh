#ifndef __BOMB_HH_
# define __BOMB_HH_

#include "AObject.hh"

class Bomb
{
public:
  Bomb(int, int, std::pair<int, int>);
  ~Bomb();
  Bomb(Bomb const &);
  Bomb &operator=(Bomb const &);

  int			getRange() const;
  int			getIdx() const;
  std::pair<int, int>	getPos() const;

protected:
  int			_idx;
  int			_range;
  std::pair<int, int>	_pos;
};

#endif /* !__BOMB_HH__ */
