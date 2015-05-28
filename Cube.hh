#ifndef	CUBE
# define CUBE

#include <Model.hh>
#include "Attribute.hh"
#include "Geometry.hh"
#include "Texture.hh"
#include "AObject.hh"

class Cube : public AObject
{
private:
  // La texture utilisee pour le cube
  gdl::Texture _texture;
  // La geometrie du cube
  gdl::Geometry _geometry;
  // La vitesse de deplacement du cube
  float _speed;
public:
  Cube();
  virtual ~Cube();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif	// CUBE
