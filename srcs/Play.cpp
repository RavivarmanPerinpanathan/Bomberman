#include "Play.hh"

Play::Play()
{

}

Play::~Play()
{

}

Play::Play(Play const &c)
  : _players(c._players), _bots(c._bots)
{

}

Play			&Play::operator=(Play const &c)
{
  if (this != &c)
    {
      _players = c._players;
      _bots = c._bots;
    }
  return (*this);
}

std::vector<Player>	Play::getPlayers() const
{
  return (_players);
}

void			Play::setPlayers(std::string const &p1, std::string const &p2)
{
  if (!p1.empty())
    {
      if (!p2.empty())
	_players.push_back(Player(p2));
      _players.push_back(Player(p1));
    }
}

std::vector<Bot>	Play::getBots() const
{
  return (_bots);
}

void			Play::setBots(int bots)
{
  for (int i = 0; i < bots; ++i)
    _bots.push_back(Bot());
}

int			Play::eventHandler()
{
  /* gestion des events sur la page play */

  /* si on catch click souris sur le bouton "Play" */
  std::string	player1 = "Piwa"; /* récupère input nom p1 */
  std::string	player2 = "Wapi"; /* récupère input nom p2 */
  int		botInput = 15; /* récupère input nb bots */
  int		xMap = 15; /* récupère input x de la map */
  int		yMap = 15; /* récupère input y de la map */

  Map			map(xMap, yMap);

  setPlayers(player1, player2);
  setBots(botInput);
  if (map.setRandomMap(getPlayers(), getBots()) == 1)
    return (1);
  map.showMap();
  /* --------------------------------------------- */
  return (0);
}

void			Play::showPlay()
{
  /* affichage de la page play */
  eventHandler();
}
