#ifndef _RANK_
# define _RANK_

#include <Model.hh>
#include "AObject.hh"
#include "Geometry.hh"
#include "Texture.hh"
#include "Attribute.hh"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <SdlContext.hh>
#include <Input.hh>
#include <Clock.hh>
#include <Game.hh>
#include "Menu.hh"

class	Rank: public Menu
{
public:
  Rank();
  ~Rank();
};

#endif /* !_RANK_  */
