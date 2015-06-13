#ifndef __BOT_HH__
# define __BOT_HH__

#include <iostream>
#include <string>
#include "AObject.hh"

class Bot : public AObject
{
public:
  Bot();
  ~Bot();
  Bot(Bot const &);
  Bot	&operator=(Bot const &);
  virtual bool	initialize();
  virtual void	update();
  virtual void	draw();
  glm::mat4	getTransformation();

  std::pair<int, int>	getPos() const;
  void			setPos(std::pair<int, int>);

private:
  
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;


protected:
  std::pair<int, int>	_pos;
};

#endif /* !__BOT_HH__ */
