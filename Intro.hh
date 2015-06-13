//
// Intro.hh for tran_2 in /home/tran_2/bomberman/bomberman
// 
// Made by Viet Dung Tran
// Login   <tran_2@epitech.net>
// 
// Started on  Sun Jun  7 13:02:32 2015 Viet Dung Tran
// Last update Tue Jun  9 07:23:13 2015 ravivarman perinpanathan
//

#ifndef _INTRO_HH_
# define _INTRO_HH_

#include <Model.hh>
#include "AObject.hh"
#include "Geometry.hh"
#include "Texture.hh"
#include "Attribute.hh"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <SdlContext.hh>
#include <Input.hh>
#include <Clock.hh>
#include <Game.hh>

class	Intro : public AObject
{
public:
  Intro();
  ~Intro();
  virtual bool	initialize();
  //  virtual void	initialize(float const &, float const &, float const &);
  //virtual void	update(gdl::Clock const &clock, gdl::Input & input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  //virtual void	draw();
private:
  gdl::Geometry	_geometry;
  gdl::Model	_model;
  gdl::Texture	_texture;
  float		_speed;
};

#endif /* !_INTRO_HH_ */
