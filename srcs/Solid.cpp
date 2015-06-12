#include "Solid.hh"

Solid::Solid()
{

}

Solid::~Solid()
{

}

bool	Solid::initialize()
{
  if (_texture.load("./LibBomberman_linux_x64/assets/marvin.fbm/Main_texture_diffuse2.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  // _geometry.setColor(glm::vec4(1, 0, 0, 1));
  // _geometry.pushVertex(glm::vec3(2, -0.5, -0.5));
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  // _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  // _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  // _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  // _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  // _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // _geometry.build();

  // _geometry.pushVertex(glm::vec3(0 + x, 0 + y, 0));

  return (true);
}

void	Solid::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Solid::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
