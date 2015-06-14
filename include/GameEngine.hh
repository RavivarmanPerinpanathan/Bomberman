#ifndef	__GAME_ENGINE_HH__
# define __GAME_ENGINE_HH__

#pragma once
#include <vector>
#include "AObject.hh"
#include "BlockFactory.hh"
#include "Map.hh"
#include "Audio.hh"

class GameEngine : public gdl::Game
{
public:
  GameEngine(Map &);
  ~GameEngine();

  bool			initialize();
  bool			update();
  void			drawCharacters();
  void			draw();
  void			translate(glm::vec3 const &v);
  void			rotate(glm::vec3 const& axis, float angle);
  void			scale(glm::vec3 const& scale);
  glm::mat4		getTransformation();
  void			setView(float, float, float);

private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
  glm::vec3		_position;
  glm::vec3		_rotation;
  glm::vec3		_scale;
  glm::mat4		_projection;
  glm::mat4		_transformation;

  std::map<Map::status, AObject*> _objects;
  std::vector<AObject*>	_players;
  std::vector<AObject*>	_bots;
  Map			_map;
  BlockFactory		_blockFactory;
  Audio			_audio;
  float			_baseX;
  float			_baseY;
  float			_baseZ;
  int			_size;
};

#endif /* !__GAME_ENGINE_HH__ */
