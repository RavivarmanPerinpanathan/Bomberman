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

#define WIDTH 1024
#define HEIGHT 768

class Menu : public gdl::Game
{
public:
  Menu();
  ~Menu();
  Menu(Menu const &);
  Menu	&operator=(Menu const &);
  int				run(Map);
  bool				update();
  bool				initialize();
  glm::mat4 				getTransformation();
  void				draw();
  std::vector<AObject*> 	_objects;
  gdl::BasicShader		_shader;
  gdl::Geometry			_geometry;
  gdl::SdlContext		_context;
  gdl::Texture			_texture;
  gdl::Clock			_clock;
  gdl::Input 			_input;
  glm::mat4 			_projection;
  glm::mat4 			_transformation;
  glm::vec3			_position;

private:
  int				_playerInput;
  int				_botInput;
  int				_xMap;
  int				_yMap;
  float				_speed;
  float				_time;
};

#endif /* !__MENU_HH__ */
