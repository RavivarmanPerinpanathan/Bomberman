#ifndef __MENU_HH__
# define __MENU_HH__

#include <iostream>
#include <string>
#include <SdlContext.hh>
#include <vector>
#include "Map.hh"
#include "GameEngine.hh"
#include "Texture.hh"

class Menu
{
public:
  Menu();
  ~Menu();
  Menu(Menu const &);
  Menu	&operator=(Menu const &);

  int			eventHandler();
  bool			showMenu();
  int			run(Map);
  std::vector<AObject*> _objects;
  gdl::BasicShader	_shader;
  gdl::Geometry		_geometry;
  gdl::SdlContext	_context;
  float			_speed;
  gdl::Texture		_texture;
};

#endif /* !__MENU_HH__ */
