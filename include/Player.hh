#ifndef __PLAYER_HH__
# define __PLAYER_HH__

#include "AObject.hh"

class Player : public AObject
{
public:
  Player();
  virtual ~Player();

  virtual bool		initialize();
  virtual bool		update(gdl::SdlContext, gdl::Input &);
  virtual void		draw(gdl::AShader &shader, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
  gdl::Clock		_clock;
};

#endif /* !__PLAYER_HH__ */
