#include "Bomb.hh"

Bomb::Bomb()
{

}

Bomb::~Bomb()
{

}

Bomb::Bomb(Bomb const &c)
{
  (void)c;
}

Bomb		&Bomb::operator=(Bomb const &c)
{
  (void)c;
  return (*this);
}
