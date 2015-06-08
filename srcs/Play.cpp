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
    _players.push_back(Player(p1));
  if (!p2.empty())
    _players.push_back(Player(p2));
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

void			Play::eventHandler()
{
  /* gestion des events sur la page play */

  /* si on catch click souris sur le bouton "Play" */
  std::string	player1 = "Piwa"; /* récupère input nom p1 */
  std::string	player2 = "Wapi"; /* récupère input nom p2 */
  int		botInput = 3; /* récupère input nb bots */
  int		xMap = 20; /* récupère input x de la map */
  int		yMap = 20; /* récupère input y de la map */

  Map			map(xMap, yMap);

  setPlayers(player1, player2);
  setBots(botInput);
  map.setRandomMap(getPlayers(), getBots());
  map.showMap();
  /* --------------------------------------------- */
}

void			Play::showPlay()
{
  /* affichage de la page play */
  eventHandler();
}
