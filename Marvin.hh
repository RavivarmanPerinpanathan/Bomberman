//
// Model.hh for Model in /home/perinp_r/Bitbucket/bomberman
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Tue May 19 16:56:42 2015 ravivarman perinpanathan
// Last update Wed May 20 02:26:45 2015 ravivarman perinpanathan
//

#ifndef _MARVIN_HH_
#define	_MARVIN_HH_


#include <Model.hh>
#include "AObject.hh"
#include "Geometry.hh"
#include "Texture.hh"
#include "Attribute.hh"
#include "Pos3f.hh"

class Marvin : public AObject
{
public:
  Marvin();
  ~Marvin();
  virtual bool	initialize();
  virtual void	initialize(float const &, float const &, float const &);
  virtual void	update(gdl::Clock const &clock, gdl::Input & input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
  
private:
  
  gdl::Geometry	_geometry;
  gdl::Model	_model;
  float		_speed;
  Pos3f		_pos;
  Pos3f		_rotation;
};

#endif /* _MARVIN_HH_ */
