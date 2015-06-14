#ifndef __RANGE_HH__
# define __RANGE_HH__

#include "AObject.hh"

class Range : public AObject
{
public:
  Range();
  virtual ~Range();

  virtual bool		initialize();
  virtual void		update(gdl::Input &input);
  virtual void		draw(gdl::AShader &shader, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
};

#endif /* !__RANGE_HH__ */
