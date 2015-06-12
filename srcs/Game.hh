#ifndef __GAME_HH__
# define __GAME_HH__

#include <iostream>
#include <string>
#include <Model.hh>
#include <vector>
#include <map>
#include <Game.hh>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Input.hh>
#include <Attribute.hh>
#include <Geometry.hh>
#include <Texture.hh>

#include "Map.hh"
#include "Player.hh"
#include "Bot.hh"
#include "Bomb.hh"
#include "Timer.hh"
#include "../GameEngine.hh"

class Game
{
public:
  Game(Map &);
  virtual ~Game();
  Game(Game const &);
  Game		&operator=(Game const &);

  void		dropBomb(int);
  bool		eventHandler(gdl::Input &);
  int		run();

protected:
  Map			_map;
  float			_speed;
  int			_on;
};

#endif /* !__GAME_HH__ */
