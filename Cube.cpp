#include "Cube.hh"

Cube::Cube()
{

}

Cube::~Cube()
{

}

bool	Cube::initialize()
{
  return (true);
}

void	Cube::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

glm::mat4 Cube::getTransformation()
{
  glm::mat4 transform(1);
  transform = glm::scale(transform, glm::vec3(20, 20, 20));
  transform = glm::translate(transform, _position);
  // On applique ensuite les rotations selon les axes x, y et z

  return (transform);
}

void Cube::draw(gdl::AShader &shader, gdl::Clock const &clock, int x, int y)
{
   (void)clock;
  if (_texture.load("./srcs/brick.tga") == false)
    {
      std::cerr << "Cannot load the ground texture" << std::endl;
      //return (false);
    }

  _position = glm::vec3(x, y, 0);

  //face
  _geometry.setColor(glm::vec4(0.9f, 0.9f, 0.9f, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));

   //dessus
  _geometry.setColor(glm::vec4(0.5f, 0.5f, 0.5f, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  //droite
  _geometry.setColor(glm::vec4(0.3f, 0.3f, 0.2f, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 0));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  //droite
  _geometry.setColor(glm::vec4(0.3f, 0.3f, 0.2f, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 0));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.build();

  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

