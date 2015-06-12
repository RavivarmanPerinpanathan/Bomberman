#include "Solid.hh"

Solid::Solid()
{

}

Solid::~Solid()
{

}

bool	Solid::initialize()
{
  return (true);
}

void	Solid::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Solid::draw(gdl::AShader &shader, gdl::Clock const &clock, int x, int y)
{
  (void)clock;
  if (_texture.load("./srcs/brick.tga") == false)
    {
      std::cerr << "Cannot load the ground texture" << std::endl;
      //return (false);
    }

  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(x*20, 0, 0));
  _geometry.pushVertex(glm::vec3(x*20, y*20, 0));
  _geometry.pushVertex(glm::vec3(0, y*20, 0));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));

  _geometry.build();

  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
