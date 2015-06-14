#ifndef __SPEED_HH__
# define __SPEED_HH__

#include "AObject.hh"

class Speed : public AObject
{
public:
  Speed();
  virtual ~Speed();

  virtual bool		initialize();
  virtual bool		update(gdl::SdlContext, gdl::Input &);
  virtual void		draw(gdl::AShader &, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
};

#endif /* !__SPEED_HH__ */
