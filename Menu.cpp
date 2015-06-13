#include "Menu.hh"

Menu::Menu()
{
}

Menu::~Menu()
{
}

bool	Menu::initialize()
{
  _speed = 10.0f;
  if (_texture.load("./") == false)
    {
      std::cerr << " Couldnt load the Menu  image" << std::endl;
      return (false);
    }

  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  return (true);
}

void	Menu::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
}

void	Menu::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
