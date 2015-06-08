#ifndef __PLAY_HH__
# define __PLAY_HH__

#include <iostream>
#include <string>
#include <vector>
#include "Map.hh"
#include "Player.hh"
#include "Bot.hh"

class Play
{
public:
  Play();
  ~Play();
  Play(Play const &);
  Play	&operator=(Play const &);

  std::vector<Player>	getPlayers() const;
  void			setPlayers(std::string const &, std::string const &);
  std::vector<Bot>	getBots() const;
  void			setBots(int);

  void			eventHandler();
  void			showPlay();

protected:
  std::vector<Player>	_players;
  std::vector<Bot>	_bots;
};

#endif /* !__PLAY_HH__ */
