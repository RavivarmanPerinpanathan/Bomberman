#include "Game.hh"
#include <typeinfo>
#include <Input.hh>
#include <stdio.h>

Game::Game(Map &map)
  : _map(map), _speed(20.0f), _on(true)
{

}

Game::~Game()
{

}

Game::Game(Game const &c)
  : _map(c._map), _speed(c._speed), _on(c._on)
{

}

Game		&Game::operator=(Game const &c)
{
  if (this != &c)
    {
      _map = c._map;
      _speed = c._speed;
      _on = c._on;
    }
  return (*this);
}

void		Game::dropBomb(int idx)
{
  if (_map.getPlayers()[idx].getSimult() > 0)
    {
      Bomb	bomb(idx, _map.getPlayers()[idx].getRange(), _map.getPlayers()[idx].getPos());
      Timer	timer(_map);

      timer.launch();
      std::cout << "out of timer" << std::endl;
      _map.getPlayers()[idx].setSimult(_map.getPlayers()[idx].getSimult() - 1);
    }
}

bool		Game::eventHandler(gdl::Input &input)
{
  if (input.getKey(SDLK_ESCAPE) || input.getInput(SDL_QUIT))
    return false;
  if (input.getKey(SDLK_UP))
    _map.updateMap(0, _map.getPlayers()[0].getPos(), std::make_pair(-1, 0));
  if (input.getKey(SDLK_DOWN))
    _map.updateMap(0, _map.getPlayers()[0].getPos(), std::make_pair(1, 0));
  if (input.getKey(SDLK_LEFT))
    _map.updateMap(0, _map.getPlayers()[0].getPos(), std::make_pair(0, -1));
  if (input.getKey(SDLK_RIGHT))
    _map.updateMap(0, _map.getPlayers()[0].getPos(), std::make_pair(0, 1));
  if (input.getKey(SDLK_RSHIFT))
    dropBomb(0);
  if (input.getKey(SDLK_z))
    _map.updateMap(1, _map.getPlayers()[1].getPos(), std::make_pair(-1, 0));
  if (input.getKey(SDLK_s))
    _map.updateMap(1, _map.getPlayers()[1].getPos(), std::make_pair(1, 0));
  if (input.getKey(SDLK_q))
    _map.updateMap(1, _map.getPlayers()[1].getPos(), std::make_pair(0, -1));
  if (input.getKey(SDLK_d))
    _map.updateMap(1, _map.getPlayers()[1].getPos(), std::make_pair(0, 1));
  if (input.getKey(SDLK_SPACE))
    dropBomb(1);
  return true;
}

int		Game::run()
{
  // gdl::SdlContext	context;
  // gdl::Clock		clock;
  // gdl::Input		input;
  // double  seconde = 0;

  GameEngine engine(_map);

  // On crees on engine GameEngine  engine;
  if (engine.initialize() == false)
      return (EXIT_FAILURE);

  std::cout << "hahaha" << std::endl;
  while (engine.update()!=false)
    engine.draw();

  return
    EXIT_SUCCESS;
  
  // if (!context.start(_map.getWidth() * 20, _map.getHeight() * 20, "My bomberman!"))
  //   return EXIT_FAILURE;

 //  while ((    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * 20.0f);
 // < 40)
 //    {
 //      context.updateClock(clock);
 //      std::cout << "clock over : " << clock.getElapsed() << std::endl;
 //    }
  // while (_on)
  //   {
  //     context.updateClock(clock);
  //     seconde += clock.getElapsed();
  //     if (seconde > 1 && (round(seconde + 0.5) %){
  // 	printf("%0f\n", seconde);
  //     }
  //     context.updateInputs(input);
  //     _on = eventHandler(input);
  //     //context.flush();
  //   }
  // return EXIT_SUCCESS;
}
