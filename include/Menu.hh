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
#include <glm/gtc/matrix_transform.hpp>

class Menu : public gdl::Game
{
public:
  Menu();
  ~Menu();
  Menu(Menu const &);
  Menu	&operator=(Menu const &);

  bool				update();
  bool				initialize();
  glm::mat4 				getTransformation();
  void				draw();
  std::vector<AObject*> 	_objects;
  gdl::BasicShader		_shader;
  gdl::Geometry			_geometry;
  gdl::Geometry			_geometry2;
  
  gdl::SdlContext		_context;
  float				_speed;
  gdl::Texture			_texture;
  gdl::Texture			_texture2;
  gdl::Clock			_clock;
  int				_playerInput;
  gdl::Input 			_input;
  int				_botInput; /* récupère input nb bots */
  int				_xMap; /* récupère input x de la map */
  int				_yMap; /* récupère input y de la map */
  glm::mat4 			_projection;
  glm::mat4 			_transformation;
  glm::vec3			_position;
};

#endif /* !__MENU_HH__ */
