#ifndef	__BREAK_HH__
# define __BREAK_HH__

#include "AObject.hh"

class Break : public AObject
{
public:
  Break();
  virtual ~Break();

  virtual bool		initialize();
  virtual void		update(gdl::Input &input);
  virtual void		draw(gdl::AShader &shader, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
};

#endif /* !__BREAK_HH__ */
