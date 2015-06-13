//
// Created by navarr_a on 06/06/15.
//

#include "Bot.hh"

Bot::Bot()
{

}

Bot::~Bot()
{

}

Bot::Bot(Bot const &c)
  : _pos(c._pos)
{

}

Bot		&Bot::operator=(Bot const &c)
{
  if (this != &c)
    {
      _pos = c._pos;
    }
  return (*this);
}

std::pair<int, int>	Bot::getPos() const
{
  return (_pos);
}

void			Bot::setPos(std::pair<int, int> pos)
{
  _pos = pos;
}

bool	Bot::initialize()
{
  return (true);
}

void	Bot::update()
{}

void	Bot::draw()
{}

glm::mat4	Bot::getTransformation()
{
  glm::mat4	transform(1);
  return (transform);
}
