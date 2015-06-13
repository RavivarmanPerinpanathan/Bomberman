#include "Simult.hh"

Simult::Simult()
{}

Simult::~Simult()
{}

bool	Simult::initialize()
{
  return (true);
}

void	Simult::update()
{}

void	Simult::draw()
{}

glm::mat4 Simult::getTransformation()
{
  glm::mat4 transform(1);
  return (transform);
}
