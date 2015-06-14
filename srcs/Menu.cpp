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
  int		playerInput = 2;
  int		botInput = 10; /* récupère input nb bots */
  int		xMap = 30; /* récupère input x de la map */
  int		yMap = 20; /* récupère input y de la map */

  Map		map(xMap, yMap, playerInput, botInput);

  if (map.getWidth() < 10 || map.getHeight() < 10 || map.setRandomMap() == 1)
    return (1);
  // map.showMap();
  run(map);
  /* --------------------------------------------- */
  return (0);
}

int			Menu::run(Map map)
{
  GameEngine engine(map);

  if (engine.initialize() == false)
    return (EXIT_FAILURE);
  while (engine.update()!=false)
    engine.draw();
  return (EXIT_SUCCESS);
}

void			Menu::showMenu()
{
  /* affichage de la page play */
  eventHandler();
}
