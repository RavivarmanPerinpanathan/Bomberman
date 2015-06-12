#include "Menu.hh"

Menu::Menu()
{

}

Menu::~Menu()
{

}

Menu::Menu(Menu const &c)
{
  (void)c;
}

Menu			&Menu::operator=(Menu const &c)
{
  if (this != &c)
    {

    }
  return (*this);
}

int			Menu::eventHandler()
{
  /* gestion des events sur la page play */

  /* si on catch click souris sur le bouton "Menu" */
  std::string	player1 = "Piwa"; /* récupère input nom p1 */
  std::string	player2 = "Wapi"; /* récupère input nom p2 */
  int		botInput = 10; /* récupère input nb bots */
  int		xMap = 80; /* récupère input x de la map */
  int		yMap = 50; /* récupère input y de la map */

  Map		map;

  if (xMap < 10 || yMap < 10)
    return (1);
  map.setWidth(xMap);
  map.setHeight(yMap);
  map.setRandomMap();
  if (map.getTmpMap().size() < ((map.getPlayers().size() * 5) + (map.getBots().size() * 5)))
    return (1);
  map.setPlayers(player1, player2);
  map.setBots(botInput);
  map.setPlayersMap();
  map.setBotsMap();
  map.setBlockMap(5, Map::SOLID);
  map.setBlockMap(10, Map::BREAK);
  map.showMap();

  Game			game(map);

  game.run();
  /* --------------------------------------------- */
  return (0);
}

void			Menu::showMenu()
{
  /* affichage de la page play */
  eventHandler();
}
