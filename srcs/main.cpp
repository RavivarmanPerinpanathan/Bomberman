#include <cstdlib>
#include "Menu.hh"

int	main()
{
  Menu	menu;

    if (menu.initialize() == false)
      return (EXIT_FAILURE);
    while(menu.update()!=false)
      menu.draw();
  return (EXIT_SUCCESS);
}
