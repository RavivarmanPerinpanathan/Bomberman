#include "Player.hh"

Player::Player()
{

}

Player::~Player()
{

}

Player::Player(Player const &c)
{
  (void)c;
}

Player		 &Player::operator=(Player const &c)
{
  if (this != &c)
    {
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

bool	Player::initialize()
{
  return (true);
}

void	Player::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void Player::draw(gdl::AShader &shader, gdl::Clock const &clock, int x, int y)
{
  (void)clock;
  (void)shader;
  (void)x;
  (void)y;
}

glm::mat4 Player::getTransformation()
{
  glm::mat4 transform(1);

  return (transform);
}
