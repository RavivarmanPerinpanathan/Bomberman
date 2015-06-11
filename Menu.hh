#ifndef _MENU_
# define _MENU_

#include <Model.hh>
#include "AObject.hh"
#include "Geometry.hh"
#include "Texture.hh"
#include "Attribute.hh"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <SdlContext.hh>
#include <Input.hh>
#include <Clock.hh>
#include <Game.hh>

class	Menu: public AObject
{
public:
  Menu();
  ~Menu();
  virtual bool  initialize();
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual void  update(gdl::Clock const &clock, gdl::Input &input);
  
private:
  gdl::Geometry	_geometry;
  gdl::Texture	_texture;
  gdl::Model	_model;
};

#endif /* !_MENU_  */
