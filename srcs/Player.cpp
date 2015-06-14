#include "Player.hh"

Player::Player()
{
  _range = 2;
  _simult = 1;
  _speed = 0.3f;
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

bool		Player::update(gdl::SdlContext context, gdl::Input &input)
{
  _time += _clock.getElapsed();
  context.updateClock(_clock);
  if (_time > _speed)
    {
      if (getId() == 0 && input.getKey(SDLK_UP))
	updateMap(getPos(), std::make_pair(1, 0));
      if (getId() == 0 && input.getKey(SDLK_DOWN))
	updateMap(getPos(), std::make_pair(-1, 0));
      if (getId() == 0 && input.getKey(SDLK_LEFT))
	updateMap(getPos(), std::make_pair(0, -1));
      if (getId() == 0 && input.getKey(SDLK_RIGHT))
	updateMap(getPos(), std::make_pair(0, 1));
      if (getId() == 0 && input.getKey(SDLK_RSHIFT))
	if (dropBomb() == false)
	  return false;
      if (getId() == 1 && input.getKey(SDLK_z))
	updateMap(getPos(), std::make_pair(1, 0));
      if (getId() == 1 && input.getKey(SDLK_s))
	updateMap(getPos(), std::make_pair(-1, 0));
      if (getId() == 1 && input.getKey(SDLK_q))
	updateMap(getPos(), std::make_pair(0, -1));
      if (getId() == 1 && input.getKey(SDLK_d))
	updateMap(getPos(), std::make_pair(0, 1));
      if (getId() == 1 && input.getKey(SDLK_SPACE))
	if (dropBomb() == false)
	  return false;
    }
  for (std::vector<AObject *>::iterator it = _bomb.begin(); it != _bomb.end(); ++it)
    if ((*it)->update(context, input) == false)
      {
	updateBomb(it - _bomb.begin(), (*it));
	break;
      }
  return true;
}

void		Player::draw(gdl::AShader &shader, int x, int y)
{
  _position = glm::vec3(x, y, 0);
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
  for (std::vector<AObject *>::iterator it = _bomb.begin(); it != _bomb.end(); ++it)
    (*it)->draw(shader, (*it)->getPos().second, (*it)->getPos().first);
}

glm::mat4	Player::getTransformation()
{
  glm::mat4	transform(1);

  transform = glm::scale(transform, glm::vec3(20, 20, 20));
  transform = glm::translate(transform, _position);
  return (transform);
}
