#include "Player.hh"

Player::Player(std::string const &name)
  : _name(name), _speed(300000), _range(2), _simult(1)
{

}

Player::~Player()
{

}

Player::Player(Player const &c)
  : _name(c._name), _speed(c._speed), _range(c._range), _simult(c._simult), _pos(c._pos)
{

}

bool	Player::initialize()
{
  return (true);
}

void	Player::update()
{}

void	Player::draw()
{}

glm::mat4	Player::getTransformation()
{
  glm::mat4	transform(1);
  return (transform);
}

Player		 &Player::operator=(Player const &c)
{
  if (this != &c)
    {
      _name = c._name;
      _speed = c._speed;
      _range = c._range;
      _simult = c._simult;
      _pos = c._pos;
    }
  return (*this);
}

std::string		Player::getName() const
{
  return (_name);
}

useconds_t		Player::getSpeed() const
{
  return (_speed);
}

void			Player::setSpeed(useconds_t speed)
{
  _speed = speed;
}

int			Player::getRange() const
{
  return (_range);
}

void			Player::setRange(int range)
{
  _range = range;
}

int			Player::getSimult() const
{
  return (_simult);
}

void			Player::setSimult(int simult)
{
  _simult = simult;
}

std::pair<int, int>	Player::getPos() const
{
  return (_pos);
}

void			Player::setPos(std::pair<int, int> pos)
{
  _pos = pos;
}
