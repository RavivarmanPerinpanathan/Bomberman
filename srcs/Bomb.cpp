#include "Bomb.hh"

Bomb::Bomb(int idx, int range, std::pair<int, int> pos)
  : _idx(idx), _range(range), _pos(pos)
{

}

Bomb::~Bomb()
{

}

Bomb::Bomb(Bomb const &c)
  : _idx(c._idx), _range(c._range), _pos(c._pos)
{

}

Bomb		&Bomb::operator=(Bomb const &c)
{
  if (this != &c)
    {
      _idx = c._idx;
      _range = c._range;
      _pos = c._pos;
    }
  return (*this);
}

int			Bomb::getRange() const
{
  return (_range);
}

int			Bomb::getIdx() const
{
  return (_idx);
}

std::pair<int, int>	Bomb::getPos() const
{
  return (_pos);
}

bool	Bomb::initialize()
{
  return (true);
}

void	Bomb::update()
{}

void	Bomb::draw()
{}

glm::mat4	Bomb::getTransformation()
{
  glm::mat4	transform(1);
  return (transform);
}
