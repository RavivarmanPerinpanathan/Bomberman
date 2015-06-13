#ifndef __AOBJECT_HH__
# define __AOBJECT_HH__

#include <iostream>
#include <string>
#include <SdlContext.hh>
#include <Game.hh>
#include <Input.hh>
#include <Clock.hh>
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <Model.hh>
#include "Texture.hh"
#include "Geometry.hh"
#include "Attribute.hh"

class AObject
{
public:
  AObject();
  virtual ~AObject();

  virtual bool initialize(int, int) = 0;
  virtual void update(gdl::Clock const &, gdl::Input &) = 0;
  virtual void draw(gdl::AShader &, gdl::Clock const &) = 0;
  void translate(glm::vec3 const &);
  void rotate(glm::vec3 const&, float);
  void scale(glm::vec3 const&);
  glm::mat4 getTransformation();

protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
};

#endif /* !__AOBJECT_HH__ */