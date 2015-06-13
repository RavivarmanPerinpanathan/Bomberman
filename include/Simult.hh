#ifndef __SIMULT_HH_
# define __SIMULT_HH_

#include "AObject.hh"

class	Simult : public AObject
{
public:
  Simult();
  virtual	~Simult();
  virtual bool	initialize();
  virtual void	update();
  virtual void	draw();
  glm::mat4	getTransformation();

private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
};

#endif /* !__SIMULT_HH_ */
