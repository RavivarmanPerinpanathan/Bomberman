#include "Player.hh"

Player::Player()
{

}

Player::~Player()
{

}

bool		Player::initialize()
{
  if (_texture.load("./img/brick.tga") == false)
    {
      std::cerr << "Cannot load the ground texture" << std::endl;
      return (false);
    }

  _geometry.setColor(glm::vec4(0.0f, 0.0f, 1.0f, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));

  _geometry.setColor(glm::vec4(0.0f, 0.0f, 1.0f, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.setColor(glm::vec4(0.0f, 0.0f, 1.0f, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 0));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));

  _geometry.setColor(glm::vec4(0.0f, 0.0f, 1.0f, 1));
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

void		Player::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  // (void)input;
  if (getId() == 0 && input.getKey(SDLK_UP))
    updateMap(getPos(), std::make_pair(-1, 0));
  if (getId() == 0 && input.getKey(SDLK_DOWN))
    updateMap(getPos(), std::make_pair(1, 0));
  if (getId() == 0 && input.getKey(SDLK_LEFT))
    updateMap(getPos(), std::make_pair(0, -1));
  if (getId() == 0 && input.getKey(SDLK_RIGHT))
    updateMap(getPos(), std::make_pair(0, 1));
  if (getId() == 1 && input.getKey(SDLK_z))
    updateMap(getPos(), std::make_pair(-1, 0));
  if (getId() == 1 && input.getKey(SDLK_s))
    updateMap(getPos(), std::make_pair(1, 0));
  if (getId() == 1 && input.getKey(SDLK_q))
    updateMap(getPos(), std::make_pair(0, -1));
  if (getId() == 1 && input.getKey(SDLK_d))
    updateMap(getPos(), std::make_pair(0, 1));
}

void		Player::draw(gdl::AShader &shader, gdl::Clock const &clock, int x, int y)
{
  (void)clock;
  // (void)shader;
  // (void)x;
  // (void)y;
  _position = glm::vec3(x, y, 0);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

glm::mat4	Player::getTransformation()
{
  glm::mat4	transform(1);
  transform = glm::scale(transform, glm::vec3(20, 20, 20));
  transform = glm::translate(transform, _position);
  return (transform);
}
