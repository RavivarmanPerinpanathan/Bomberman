#ifndef	__GAME_ENGINE_HH__
# define __GAME_ENGINE_HH__

#pragma once
// #include <glm/glm.hpp>
#include "AObject.hh"
#include "BlockFactory.hh"
#include "Map.hh"
#include "Audio.hh"
// #include "Cube.hh"

class GameEngine : public gdl::Game
{
public:
  GameEngine(Map &);
  ~GameEngine();

  bool initialize();
  bool update();
  void draw();
  void translate(glm::vec3 const &v);
  void rotate(glm::vec3 const& axis, float angle);
  void scale(glm::vec3 const& scale);
  glm::mat4 getTransformation();

private:
  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  std::vector<AObject*> _objects;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
  Map			_map;
   BlockFactory		_blockFactory;
  Audio audio;
};

#endif /* !__GAME_ENGINE_HH__ */
