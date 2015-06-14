#ifndef __AOBJECT_HH__
# define __AOBJECT_HH__

#include <iostream>
#include <string>
#include <SdlContext.hh>
#include <Game.hh>
#include <Input.hh>
#include <Clock.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <Model.hh>
#include "Texture.hh"
#include "Geometry.hh"
#include "Attribute.hh"
#include "Map.hh"

class AObject
{
public:
  AObject();
  virtual ~AObject();

  int			getId() const;
  void			setId(int id);
  std::pair<int, int>	getPos() const;
  void			setPos(std::pair<int, int>);
  float			getSpeed() const;
  void			setSpeed(float);
  int			getSimult() const;
  void			setSimult(int);
  int			getRange() const;
  void			setRange(int);
  Map			*getMap();
  void			setMap(Map *);

  bool			dropBomb();
  bool			bombAround(int, int, AObject *);
  void			updateBomb(int, AObject *);
  void			updateStat(Map::status);
  void			updateMap(std::pair<int, int>, std::pair<int, int>);
  virtual bool		initialize() = 0;
  virtual bool		update(gdl::SdlContext, gdl::Input &) = 0;
  virtual void		draw(gdl::AShader &, int, int) = 0;
  void			translate(glm::vec3 const &);
  void			rotate(glm::vec3 const&, float);
  void			scale(glm::vec3 const&);
  glm::mat4		getTransformation();

protected:
  glm::vec3		_position;
  glm::vec3		_rotation;
  glm::vec3		_scale;
  std::pair<int, int>	_pos;
  int			_id;
  Map			*_map;
  float			_time;
  float			_speed;
  int			_simult;
  int			_range;
  std::vector<AObject*>	_bomb;
  // BlockFactory		_factory;
};

#endif /* !__AOBJECT_HH__ */
