#ifndef	__SOLID_HH__
# define __SOLID_HH__

#include "AObject.hh"

class Solid : public AObject
{
public:
  Solid();
  virtual ~Solid();

  virtual bool		initialize();
  virtual void		update(gdl::SdlContext, gdl::Input &);
  virtual void		draw(gdl::AShader &, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
};

#endif /* !__SOLID_HH__ */
