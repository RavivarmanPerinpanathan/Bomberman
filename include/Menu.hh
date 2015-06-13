#ifndef __MENU_HH__
# define __MENU_HH__

#include <iostream>
#include <string>
#include "AObject.hh"
#include <SdlContext.hh>
#include <vector>
#include "Map.hh"
#include "GameEngine.hh"
#include "Texture.hh"
#include <Input.hh>

class Menu : public AObject
{
public:
  Menu();
  ~Menu();
  Menu(Menu const &);
  Menu	&operator=(Menu const &);

  int			eventHandler(gdl::Input &input);
  bool			showMenu();
  bool			initilize();
  int			run(Map);
  std::vector<AObject*> _objects;
  gdl::BasicShader	_shader;
  gdl::Geometry		_geometry;
  gdl::SdlContext	_context;
  float			_speed;
  gdl::Texture		_texture;
};

#endif /* !__MENU_HH__ */
