#ifndef __BOT_HH__
# define __BOT_HH__

#include "AObject.hh"

class Bot : public AObject
{
public:
  Bot();
  virtual ~Bot();

  virtual bool		initialize();
  virtual void		update(gdl::Input &input);
  virtual void		draw(gdl::AShader &shader, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
};

#endif /* !__BOT_HH__ */
