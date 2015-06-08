#include "Player.hh"

Player::Player(std::string const &name)
  : _name(name)
{

}

Player::~Player()
{

}

Player::Player(Player const &c)
  : _name(c._name), _pos(c._pos)
{

}

Player		 &Player::operator=(Player const &c)
{
  if (this != &c)
    {
      _name = c._name;
      _pos = c._pos;
    }
  return (*this);
}

std::string		Player::getName() const
{
  return (_name);
}

std::pair<int, int>	Player::getPos() const
{
  return (_pos);
}

void			Player::setPos(std::pair<int, int> pos)
{
  _pos = pos;
}
