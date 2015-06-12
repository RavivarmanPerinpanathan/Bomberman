#ifndef	__SOLID_HH__
# define __SOLID_HH__

#include <Model.hh>
#include "Attribute.hh"
#include "Geometry.hh"
#include "Texture.hh"
#include "../AObject.hh"

class Solid : public AObject
{
public:
  Solid();
  virtual ~Solid();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock, int x, int y);

private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float _speed;
};

#endif	/* !__SOLID_HH__ */
