//
// Model.cpp for model in /home/perinp_r/Bitbucket/bomberman
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Tue May 19 16:27:01 2015 ravivarman perinpanathan
// Last update Wed May 20 02:36:03 2015 ravivarman perinpanathan
//

#include "Model.hh"

Ironman::Ironman()
{
}
~Ironman::Ironman()
{
}

bool	Ironman::initialize()
{
  _speed = 20.0f;
  if (_model.load("./LibBomberman_linux_x64/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load marvin.fbx" << std::endl;
      return (false);
    }
  this->_pos.setPos(1.0 * SIZEBLOC, -280.0, 1 * SIZEBLOCK);
  this->_rotation.setPos(0, 0, 0);
  return (true);
}

void	Ironman::initialize(float const & x, float const & y, float const & z)
{
 if (_model.load("./LibBomberman_linux_x64/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load marvin.fbx" << std::endl;
      return (false);
    }
 this-> _pos.setPos(x, y, z);
 this-> _rotation.setPos(0, 0, 0);
}

void	Ironman::update(gdl::Clock const &clock, gdl::Input &input)
{
  _model.update(clock);
  if (input.getKey(SDLK_F1))
    //do play
}

void	Ironman::drow()//(gdl::AShader &shader, gdl::Clock const &clock)
{
  //(void)clock;
  //_model.draw();
  glPushMatrix();
  glTranslatef(this->_pos.getX(), this->_pos.getY(), this->_pos.getZ());
  glRotatef(this->_rotation.getX(), this->_rotation.getY(), this->_rotation.getZ(), 1);
  this->model.draw();
  glPopMatrix();
}
