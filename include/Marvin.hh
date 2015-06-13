//
// Model.hh for Model in /home/perinp_r/Bitbucket/bomberman
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Tue May 19 16:56:42 2015 ravivarman perinpanathan
// Last update Fri Jun  5 14:39:51 2015 ravivarman perinpanathan
//

#ifndef _MARVIN_HH_
#define	_MARVIN_HH_

#include "AObject.hh"

class Marvin : public AObject
{
public:
  Marvin();
  ~Marvin();
  virtual bool	initialize();
  //  virtual void	initialize(float const &, float const &, float const &);
  virtual void	update(gdl::Clock const &clock, gdl::Input & input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock, int x, int y);

private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  gdl::Model	_model;
  float		_speed;
  // Pos3f		_pos;
  // Pos3f		_rotation;
};

#endif /* _MARVIN_HH_ */
