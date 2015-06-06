#include "Game.hh"

Game::Game()
{

}

Game::~Game()
{

}

Game::Game(Game const &c)
{
  (void)c;
}

Game		&Game::operator=(Game const &c)
{
  (void)c;
  return (*this);
}
