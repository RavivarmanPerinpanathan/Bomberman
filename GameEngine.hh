#ifndef	GAME_ENGINE
# define	GAME_ENGINE

#pragma once
#include <vector>
#include <Game.hh>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <Model.hh>
#include "Attribute.hh"
#include "Geometry.hh"
#include "Texture.hh"
#include "AObject.hh"
#include "Cube.hh"
#include "Marvin.hh"
#include "srcs/BlockFactory.hh"
#include "srcs/Map.hh"

/*
On cree sa class GameEngine qui herite de game
*/
class GameEngine : public gdl::Game
{

public:
  GameEngine(Map &);
  bool initialize();
  bool update();
  void draw();
  ~GameEngine();

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
};

#endif	// GAME_ENGINE
