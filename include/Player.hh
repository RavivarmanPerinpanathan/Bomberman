#ifndef __PLAYER_HH__
# define __PLAYER_HH__

#include <iostream>
#include <string>
#include <unistd.h>
#include "AObject.hh"
#include "Model.hh"

class Player : public AObject
{
public:
  Player();
  ~Player();
  Player(Player const &);
  Player		&operator=(Player const &);

  std::string		getName() const;
  useconds_t		getSpeed() const;
  void			setSpeed(useconds_t);
  int			getRange() const;
  void			setRange(int);
  int			getSimult() const;
  void			setSimult(int);
  std::pair<int, int>	getPos() const;
  void			setPos(std::pair<int, int>);

  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock, int, int);
  glm::mat4		getTransformation();

protected:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  gdl::Model	_model;
  std::string		_name;
  float			_speed;
  //useconds_t		_speed;
  int			_range;
  int			_simult;
  std::pair<int, int>	_pos;
};

#endif /* !__PLAYER_HH__ */
