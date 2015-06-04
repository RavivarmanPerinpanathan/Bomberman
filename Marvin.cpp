//
// Model.cpp for model in /home/perinp_r/Bitbucket/bomberman
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Tue May 19 16:27:01 2015 ravivarman perinpanathan
// Last update Thu Jun  4 16:18:33 2015 ravivarman perinpanathan
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
  translate(glm::vec3(1, -0.5, 1));
  scale(glm::vec3(0.025, 0.025, 0.025));
  return (true);
}

void	Marvin::initialize(float const & x, float const & y, float const & z)
{
  if (_model.load("./LibBomberman_linux_x64/assets/marvin.fbx"))
    {
      std::cerr << "Cannot load marvin.fbx" << std::endl;
    }
 this-> _pos.setPos(x, y, z);
 this-> _rotation.setPos(0, 0, 0);
}

void	Marvin::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  // if (input.getKey(SDLK_F1))
  //  do play;
}

void	Marvin::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  //(void)clock;
  _model.draw(shader, getTransformation(), clock.getElapsed());
  /*glPushMatrix();
  glTranslatef(this->_pos.getX(), this->_pos.getY(), this->_pos.getZ());
  glRotatef(this->_rotation.getX(), this->_rotation.getY(), this->_rotation.getZ(), 1);
  this->model.draw();
  glPopMatrix();*/
}
