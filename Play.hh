#ifndef _PLAY_
# define _PLAY_

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

class	Play: public Menu
{
public:
  Play();
  ~Play();
  enum	playOption 
    {
      PLAYER1,
      PLAYER2,
      BOT,
      MAP_SIZE,
      LAUNCH,
      BACK
    };
  bool	_p1;
  bool	_p2;
  bool	_bot;
  int	_width;
  int	_height;
};

#endif /* !_PLAY_ */
