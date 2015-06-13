#ifndef __SPEED_HH_
# define __SPEED_HH_

#include "AObject.hh"

class Speed : public AObject
{
public:
  Speed();
  virtual	~Speed();
  virtual	bool initialize();
  virtual	void update();
  virtual	void draw();
  glm::mat4	getTransformation();
  
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
};

#endif /* !__SPEED_HH_ */
