#ifndef __PLAYER_HH__
# define __PLAYER_HH__

#include <iostream>
#include <string>
#include <unistd.h>

class Player
{
public:
  Player(std::string const &);
  ~Player();
  Player(Player const &);
  Player		&operator=(Player const &);

  std::string		getName() const;
  useconds_t		getSpeed() const;
  void			setSpeed(useconds_t);
  int			getRange() const;
  void			setRange(int);
  int			getSimult() const;
  void			setSimult(int);
  std::pair<int, int>	getPos() const;
  void			setPos(std::pair<int, int>);

protected:
  std::string		_name;
  useconds_t		_speed;
  int			_range;
  int			_simult;
  std::pair<int, int>	_pos;
};

#endif /* !__PLAYER_HH__ */
