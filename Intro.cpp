//
// Intro.cpp for tran_2 in /home/tran_2/bomberman/bomberman
// 
// Made by Viet Dung Tran
// Login   <tran_2@epitech.net>
// 
// Started on  Sun Jun  7 13:02:04 2015 Viet Dung Tran
// Last update Tue Jun  9 12:40:28 2015 ravivarman perinpanathan
//

#include <Model.hh>
#include "Intro.hh"
#include <unistd.h>

Intro::Intro() {}

Intro::~Intro() {}

bool	Intro::initialize()
{
  _speed = 20.0f;
  std::cout << "start intro" << std::endl;
   if (_texture.load("./images/Main.tga") == false)
    {
      std::cerr << "Cannot load Main.tga" << std::endl;
      return (false);
    }
// on set la color d'une premiere face
   //_geometry.setColor(glm::vec4(1, 0, 0, 1));
  // tout les pushVertex qui suivent seront de cette couleur
  // On y push les vertices d une premiere face
   //glm::mat4 _rotate;

   rotate(glm::vec3(0, 0, 0), 100);
   _geometry.pushVertex(glm::vec3(10, -10, 10));
   _geometry.pushVertex(glm::vec3(10, 10, 0));
   _geometry.pushVertex(glm::vec3(-10, 10, 0));
   _geometry.pushVertex(glm::vec3(-10, -10, 10));
  // Les UVs d'une premiere face
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
   translate(glm::vec3(1, -0.1, 10));
   //scale(glm::vec3(0.025, 0.025, 0.025));
   //usleep(100000);
  _geometry.build();
  std::cout << "end intro" << std::endl;
  return (true);
}

void	Intro::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  //(void)shader;
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
