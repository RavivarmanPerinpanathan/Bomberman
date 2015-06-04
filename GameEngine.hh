#ifndef	GAME_ENGINE
# define	GAME_ENGINE

#pragma once
#include <vector>
#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hh"
#include "Cube.hh"
#include "Marvin.hh"


/*
On cree sa class GameEngine qui herite de game
*/
class GameEngine : public gdl::Game
{

public:
  GameEngine();
  bool initialize();
  bool update();
  void draw();
  ~GameEngine();

private:
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  std::vector<AObject*> _objects;
};

#endif	// GAME_ENGINE
