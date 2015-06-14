#ifndef __BOMB_HH__
# define __BOMB_HH__

#include "AObject.hh"

class Bomb : public AObject
{
public:
  Bomb();
  virtual ~Bomb();

  virtual bool		initialize();
  virtual bool		update(gdl::SdlContext, gdl::Input &);
  virtual void		draw(gdl::AShader &shader, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
  gdl::Clock		_clock;
};

#endif /* !__BOMB_HH__ */
