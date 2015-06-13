#ifndef __MENU_HH__
# define __MENU_HH__

#include <iostream>
#include <string>
#include <vector>
#include "Map.hh"
#include "GameEngine.hh"

class Menu
{
public:
  Menu();
  ~Menu();
  Menu(Menu const &);
  Menu	&operator=(Menu const &);

  int			eventHandler();
  void			showMenu();
  int			run(Map);
  std::vector<AObject*> _objects;
};

#endif /* !__MENU_HH__ */
