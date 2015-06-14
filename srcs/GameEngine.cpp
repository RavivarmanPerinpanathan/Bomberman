#include "GameEngine.hh"
#include <stdio.h>

GameEngine::GameEngine(Map &map)
  : _map(map), _baseX(_map.getWidth()/2), _baseY((_map.getHeight()/2) - _map.getWidth()/2), _baseZ(_map.getHeight()/2 + _map.getWidth()/3), _size(20)
{

}

GameEngine::~GameEngine()
{
  // for (std::map<Map::status, AObject *>::iterator it = _objects.begin(); it != _objects.end(); ++it)
  //   delete it->second;
}

bool		GameEngine::initialize()
{
  if (!_context.start(1600, 1000, "My bomberman!"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  _shader.bind();
  if (_texture.load("./img/ground.tga") == false)
    {
      std::cerr << "Cannot load the ground texture" << std::endl;
      return (false);
    }
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(_map.getWidth(), 0, 0));
  _geometry.pushVertex(glm::vec3(_map.getWidth(), _map.getHeight(), 0));
  _geometry.pushVertex(glm::vec3(0, _map.getHeight(), 0));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.build();

  for (int Ienum = Map::SOLID; Ienum != Map::P1; Ienum++)
    {
      _objects[static_cast<Map::status>(Ienum)] = _blockFactory.createInstance(static_cast<Map::status>(Ienum));
      if (_objects[static_cast<Map::status>(Ienum)] && _objects[static_cast<Map::status>(Ienum)]->initialize() == false)
      	return false;
    }

  for (std::map<std::pair<int, int>, Map::status>::iterator it = _map.getMap().begin(); it != _map.getMap().end(); ++it)
    {
      if ((*it).second == Map::P1 || (*it).second == Map::P2)
      	{
  	  AObject *player;

  	  player = _blockFactory.createInstance((*it).second);
  	  if (player->initialize() == false)
  	    return false;
      	  player->setMap(&_map);
      	  player->setPos((*it).first);
      	  player->setMapEnum((*it).second);
  	  _players.push_back(player);
  	}
      if ((*it).second == Map::BOT)
      	{
      	  AObject *bot;

      	  bot = _blockFactory.createInstance((*it).second);
      	  if (bot->initialize() == false)
      	    return false;
      	  bot->setPos((*it).first);
      	  _bots.push_back(bot);
      	}
    }

  // _audio.setGameOverMusicVolume(80);
  // _audio.playGameOverMusic();

  float box = ((_map.getWidth() + _map.getHeight())/2) * _size * 3;

  _projection = glm::perspective(50.0f, 1600.0f / 800.0f, 0.1f, box);

  return true;
}

bool		GameEngine::update()
{

  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  if (_input.getKey(SDLK_KP_5))
    setView(_map.getWidth()/2,( _map.getHeight()/2) - (_map.getWidth()/2), (_map.getHeight()/2) + (_map.getWidth()/3));
  if (_input.getKey(SDLK_KP_2))
    setView(0, _baseY - 2, _baseZ + 0.3f);
  if (_input.getKey(SDLK_KP_PLUS))
    setView(0, 0, _baseZ + 1);
  if (_input.getKey(SDLK_KP_MINUS))
    setView(0, 0, _baseZ - 1);
  if (_input.getKey(SDLK_KP_8))
    setView(0, _baseY + 2, _baseZ - 0.3f);
  if (_input.getKey(SDLK_KP_4))
    setView(_baseX - 1, 0, 0);
  if (_input.getKey(SDLK_KP_6))
    setView(_baseX + 1, 0, 0);

  // La transformation de la camera correspond a son orientation et sa position
  // La camera sera ici situee a la position 0, 20, -100 et regardera vers la position 0, 0, 0
  //lookAt(eye, lookedatpoint, donotuch)
  _transformation = glm::lookAt(glm::vec3(_baseX*_size, _baseY*_size, _baseZ*_size), glm::vec3(_baseX*_size, (_map.getHeight()/2)*_size, 0), glm::vec3(0, 1, 0));
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);

  for (std::vector<AObject *>::iterator it = _players.begin(); it != _players.end(); ++it)
    (*it)->update(_context, _input);

  _context.updateClock(_clock);
  _context.updateInputs(_input);
  return true;
}

void		GameEngine::drawCharacters()
{
  for (std::vector<AObject *>::iterator it = _players.begin(); it != _players.end();)
    {
      if (_map.getMap()[(*it)->getPos()] == Map::EMPTY)
	{
	  // delete (*it);
	  it = _players.erase(it);
	}
      else
	{
	  (*it)->draw(_shader, (*it)->getPos().second, (*it)->getPos().first);
	  ++it;
	}
    }
  for (std::vector<AObject *>::iterator it = _bots.begin(); it != _bots.end();)
    {
      if (_map.getMap()[(*it)->getPos()] == Map::EMPTY)
	{
	  // delete (*it);
	  it = _bots.erase(it);
	}
      else
	{
	  (*it)->draw(_shader, (*it)->getPos().second, (*it)->getPos().first);
	  ++it;
	}
    }
}

void		GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _texture.bind();
  _geometry.draw(_shader, getTransformation(), GL_QUADS);
  _shader.bind();

  for (std::map<std::pair<int, int>, Map::status>::iterator it = _map.getMap().begin(); it != _map.getMap().end(); ++it)
    if (_objects[it->second])
      _objects[it->second]->draw(_shader, it->first.second, it->first.first);
  drawCharacters();
  _context.flush();
}

void		GameEngine::translate(glm::vec3 const &v)
{
  _position += v;
}

void		GameEngine::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void		GameEngine::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4      	GameEngine::getTransformation()
{
  glm::mat4    	transform(1);

  transform = glm::scale(transform, glm::vec3(20, 20, 1));
  return (transform);
}

void   		GameEngine::setView(float x, float y, float z)
{
  if (x != 0)
    _baseX = x;
  if (y != 0)
    _baseY = y;
  if (z != 0)
    _baseZ = z;
}
