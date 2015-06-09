//
// Model.cpp for model in /home/perinp_r/Bitbucket/bomberman
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Tue May 19 16:27:01 2015 ravivarman perinpanathan
// Last update Tue Jun  9 07:01:31 2015 ravivarman perinpanathan
//

#include <Model.hh>
#include "Marvin.hh"

Marvin::Marvin()
{
}

Marvin::~Marvin()
{
}

bool	Marvin::initialize()
{
  _speed = 20.0f;
  if (_model.load("./LibBomberman_linux_x64/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load marvin.fbx" << std::endl;
      return (false);
    }
  translate(glm::vec3(1, -0.1, 20));
  scale(glm::vec3(0.025, 0.025, 0.025));
  return (true);
}

// void	Marvin::initialize(float const & x, float const & y, float const & z)
// {
//   if (_model.load("./LibBomberman_linux_x64/assets/marvin.fbx"))
//     {
//       std::cerr << "Cannot load marvin.fbx" << std::endl;
//     }
//   this-> _pos.setPos(x, y, z);
//   this-> _rotation.setPos(0, 0, 0);
// }

void	Marvin::update(gdl::Clock const &clock, gdl::Input &input)
{
 if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

void	Marvin::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
