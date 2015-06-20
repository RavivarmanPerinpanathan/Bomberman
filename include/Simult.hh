#ifndef __SIMULT_HH__
# define __SIMULT_HH__

#include "AObject.hh"

class	Simult : public AObject
{
public:
  Simult();
  virtual ~Simult();

  virtual bool		initialize();
  virtual bool		update(gdl::SdlContext, gdl::Input &);
  virtual void		draw(gdl::AShader &, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
};

#endif /* !__SIMULT_HH__ */