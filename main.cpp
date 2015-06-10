//
// main.cpp for main in /home/perinp_r/Bitbucket/bomberman
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Tue May 19 12:49:55 2015 ravivarman perinpanathan
// Last update Tue May 19 14:55:32 2015 tran_1
//

#include <cstdlib>
#include "GameEngine.hh"
#include "srcs/Play.hh"

int	main()
{
  // GameEngine engine;
  // On crees on engine GameEngine  engine;
  // if (engine.initialize() == false)
  //   return (EXIT_FAILURE);
  // while (engine.update() == true)
  //   engine.draw();
  // return
  //   EXIT_SUCCESS;

  Play	play;

  play.showPlay();
  return (0);
}
