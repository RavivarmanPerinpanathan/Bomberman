#include "Speed.hh"

Speed::Speed()
{

}

Speed::~Speed()
{

}

bool		Speed::initialize()
{
  if (_texture.load("./img/speed.tga") == false)
    {
      std::cerr << "Cannot load the speed texture" << std::endl;
      return (false);
    }

  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));

  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 0));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();
  return (true);
}

bool		Speed::update(gdl::SdlContext context, gdl::Input &input)
{
  (void)context;
  (void)input;
  return true;
}

void		Speed::draw(gdl::AShader &shader, int x, int y)
{
  _position = glm::vec3(x, y, 0);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

glm::mat4	Speed::getTransformation()
{
  glm::mat4	transform(1);

  transform = glm::scale(transform, glm::vec3(20, 20, 20));
  transform = glm::translate(transform, _position);
  return (transform);
}