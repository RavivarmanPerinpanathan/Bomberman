#include <cstdlib>
#include "Menu.hh"

int	main()
{
  //Menu	menu;

  
  //menu.initialize();
//  menu.initialize();
  Menu		menu;
  if (menu.initialize() == false)
    return (EXIT_FAILURE);
  while (menu.update() != false)
    menu.draw();
  return (0);
}
