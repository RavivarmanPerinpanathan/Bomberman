#ifndef __RANGE_HH__
# define __RANGE_HH_

#include "AObject.hh"

class Range : public AObject
{
public:
  Range();
  virtual ~Range();
  virtual bool	initialize();
  virtual void	update();
  virtual void	draw();
  glm::mat4	getTransformation();

private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
};

#endif /* !__RANGE_HH_ */
