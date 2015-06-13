#ifndef __BOMB_HH_
# define __BOMB_HH_

#include "AObject.hh"

class Bomb : public AObject
{
public:
  Bomb(int, int, std::pair<int, int>);
  virtual ~Bomb();
  Bomb(Bomb const &);
  Bomb &operator=(Bomb const &);
  virtual bool	initialize();
  virtual void	 update();
  virtual void	draw();
  glm::mat4	getTransformation();

  int			getRange() const;
  int			getIdx() const;
  std::pair<int, int>	getPos() const;

private:
  
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

protected:
  int			_idx;
  int			_range;
  std::pair<int, int>	_pos;
};

#endif /* !__BOMB_HH__ */
