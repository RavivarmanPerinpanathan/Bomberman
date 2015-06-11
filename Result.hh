#ifndef _RESULT_
# define _RESULT_

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
#include "Play.hh"

class	Result: public Play
{
public:
  Result();
  ~Result();
  enum	endOption
    {
      REPLAY,
      MENU,
      EXIT
    };
  bool _replay;
  bool _menu;
  bool _exit;
};

#endif /* !_RESULT_  */
