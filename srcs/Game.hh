#ifndef __GAME_HH__
# define __GAME_HH__

#include <iostream>
#include <string>

class Game
{
public:
  Game();
  ~Game();
  Game(Game const &);
  Game		&operator=(Game const &);

  void		run();
};

#endif /* !__GAME_HH__ */
