#ifndef __PLAYER_HH__
# define __PLAYER_HH__

#include <iostream>
#include <string>
#include <unistd.h>
#include "Map.hh"
#include "AObject.hh"

class Player : public AObject
{
public:
  Player();
  virtual ~Player();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
  gdl::Model   _model;
  float                        _speed;
  //useconds_t         _speed;
};

#endif /* !__PLAYER_HH__ */
