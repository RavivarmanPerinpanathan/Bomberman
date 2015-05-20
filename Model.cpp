//
// Model.cpp for model in /home/perinp_r/Bitbucket/bomberman
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Tue May 19 16:27:01 2015 ravivarman perinpanathan
// Last update Wed May 20 02:36:03 2015 ravivarman perinpanathan
//

#include <Model.hh>
#include "Model.hh"
#include "LibBomberman_linux_x64/includes/GL/glew.h"
#include "LibBomberman_linux_x64/includes/SDL_keycode.h"

Model::Ironman::Ironman()
{
}
Model::Ironman::~Ironman()
{
}

bool	Model::Ironman::initialize()
{
  _speed = 20.0f;
  if (this->_model.load("./LibBomberman_linux_x64/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load marvin.fbx" << std::endl;
      return (false);
    }
  this->_pos.setPos(1.0 * 5 /*SIZEBLOC*/, -280.0, 1 * 5/*SIZEBLOCK*/);
  this->_rotation.setPos(0, 0, 0);
  return (true);
}

void	Model::Ironman::initialize(float const & x, float const & y, float const & z)
{
 if (_model.load("./LibBomberman_linux_x64/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load marvin.fbx" << std::endl;
      return ;
    }
 this-> _pos.setPos(x, y, z);
 this-> _rotation.setPos(0, 0, 0);
}

void	Model::Ironman::update(gdl::Clock const &clock, gdl::Input &input)
{
    (void)clock;
    (void)input;
}

void	Model::Ironman::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  this->_model.draw();
  glPushMatrix();
  glTranslatef(this->_pos.getX(), this->_pos.getY(), this->_pos.getZ());
  glRotatef(this->_rotation.getX(), this->_rotation.getY(), this->_rotation.getZ(), 1);
  this->_model.draw();
  glPopMatrix();
}
