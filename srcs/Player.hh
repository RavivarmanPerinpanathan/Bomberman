#ifndef __PLAYER_HH__
# define __PLAYER_HH__

#include <iostream>
#include <string>

class Player
{
public:
  Player(std::string const &);
  ~Player();
  Player(Player const &);
  Player		&operator=(Player const &);

  std::string		getName() const;
  std::pair<int, int>	getPos() const;
  void			setPos(std::pair<int, int>);

protected:
  std::string		_name;
  std::pair<int, int>	_pos;
};

#endif /* !__PLAYER_HH__ */
