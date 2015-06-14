#include "Simult.hh"

Simult::Simult()
{

}

Simult::~Simult()
{

}

bool		Simult::initialize()
{
  if (_texture.load("./img/brick.tga") == false)
    {
      std::cerr << "Cannot load the ground texture" << std::endl;
      return (false);
    }

  _geometry.setColor(glm::vec4(0.0f, 1.0f, 0.0f, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));

  _geometry.setColor(glm::vec4(0.0f, 1.0f, 0.0f, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.setColor(glm::vec4(0.0f, 1.0f, 0.0f, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 0));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.setColor(glm::vec4(0.0f, 1.0f, 0.0f, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 0));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();
  return (true);
}

bool		Simult::update(gdl::SdlContext context, gdl::Input &input)
{
  (void)context;
  (void)input;
  return true;
}

void		Simult::draw(gdl::AShader &shader, int x, int y)
{
  _position = glm::vec3(x, y, 0);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

glm::mat4	Simult::getTransformation()
{
  glm::mat4	transform(1);

  transform = glm::scale(transform, glm::vec3(20, 20, 20));
  transform = glm::translate(transform, _position);
  return (transform);
}
