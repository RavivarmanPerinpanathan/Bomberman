//
// Intro.cpp for tran_2 in /home/tran_2/bomberman/bomberman
// 
// Made by Viet Dung Tran
// Login   <tran_2@epitech.net>
// 
// Started on  Sun Jun  7 13:02:04 2015 Viet Dung Tran
// Last update Tue Jun  9 13:42:14 2015 Viet Dung Tran
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
   if (_texture.load("./img/Main.tga") == false)
    {
      std::cerr << "Cannot load Main.tga" << std::endl;
      return (false);
    }
   rotate(glm::vec3(0, 0, 5), -90);
   _geometry.pushVertex(glm::vec3(19, -19, 34));
   _geometry.pushVertex(glm::vec3(19, 19, 34));
   _geometry.pushVertex(glm::vec3(-19, 19, 19));
   _geometry.pushVertex(glm::vec3(-19, -19, 19));
   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));
   translate(glm::vec3(-15, 0.2, 0));
   _geometry.build();
   std::cout << "end intro" << std::endl;
   return (true);
}

void	Intro::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
