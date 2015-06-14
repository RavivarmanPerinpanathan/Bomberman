#ifndef __RANGE_HH__
# define __RANGE_HH__

#include "AObject.hh"

class Range : public AObject
{
public:
  Range();
  virtual ~Range();

  virtual bool		initialize();
  virtual bool		update(gdl::SdlContext, gdl::Input &);
  virtual void		draw(gdl::AShader &, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
};

#endif /* !__RANGE_HH__ */
