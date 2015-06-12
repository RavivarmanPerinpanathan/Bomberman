#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <Model.hh>
#include <SdlContext.hh>
#include "Attribute.hh"
#include "Geometry.hh"
#include "Texture.hh"
#include "GameEngine.hh"
#include <stdio.h>

GameEngine::GameEngine(Map &map)
  : _map(map)
{
}

bool GameEngine::initialize()
{
    if (!_context.start(800, 600, "My bomberman!")) // on cree une fenetre
      return false;
    std::cout << "faramir" << std::endl;
    // On active le test de profondeur d'OpenGL pour que les pixels que l'oeil ne voit pas ne s'affichent pas
    glEnable(GL_DEPTH_TEST);
    // On cree un shader, petit programme permettant de dessiner nos objets a l'ecran
    if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER) // le fragment shader se charge de dessiner les pixels
	|| !_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER) // le vertex shader s'occupe de projeter les points sur l'ecran
	|| !_shader.build()) {// il faut ensuite compiler son shader
      std::cout << "build" << std::endl;
      return false;
    }
      std::cout << "build success" << std::endl;

    // On place ensuite la camera (sa projection ainsi que sa transformation)
    glm::mat4 projection;
    glm::mat4 transformation;
    // La projection de la camera correspond a la maniere dont les objets vont etre dessine a l'ecran
    projection = glm::perspective(80.0f, 800.0f / 600.0f, 0.1f, 100.0f*20);
    // La transformation de la camera correspond a son orientation et sa position
    // La camera sera ici situee a la position 0, 20, -100 et regardera vers la position 0, 0, 0
    //lookAt(eye, lookedatpoint, donotuch)
    transformation = glm::lookAt(glm::vec3(40*20, -25*20, 30*20), glm::vec3(40*20, 25*20, 0), glm::vec3(0, 1, 0));
    // On doit toujours binder le shader avant d'appeler les methodes setUniform
    _shader.bind();
    _shader.setUniform("view", transformation);
    _shader.setUniform("projection", projection);

    // On va ensuite creer un cube que l'on va ajouter a la liste d'objets
    // AObject *cube = new Cube();
    // if (cube->initialize() == false)
    //   return (false);
    // _objects.push_back(cube);

    // AObject *marvin = new Marvin();
    // if (marvin->initialize() == false)
    //   return (false);
    // _objects.push_back(marvin);
   // for (std::map<std::pair<int, int>, Map::status>::iterator it = _map.getMap().begin(); it != _map.getMap().end(); ++it)
   //    {
    /*	AObject *obj;
	obj = _blockFactory.createInstance(Map::SOLID);
	if (obj->initialize() == false)
	  return false;
	// obj->draw(_shader, _clock);
	_objects.push_back(obj);
	// }*/
    return true;
}

void GameEngine::translate(glm::vec3 const &v)
{
  _position += v;
}

void GameEngine::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void GameEngine::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4 GameEngine::getTransformation()
{
  glm::mat4 transform(1); // On cree une matrice identite
  transform = glm::scale(transform, glm::vec3(20, 20, 0));
  // On applique ensuite les rotations selon les axes x, y et z

  return (transform);
}

bool GameEngine::update()
{
    // Si la touche ECHAP est appuyee ou si l'utilisateur ferme la fenetre, on quitte le programme
      if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
	return false;
    // Mise a jour des inputs et de l'horloge de jeu
    _context.updateClock(_clock);
    _context.updateInputs(_input);
    // Mise a jour des differents objets
    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->update(_clock, _input);
    return true;
}

void GameEngine::draw()
{
  std::cout << "whooo2" << std::endl;
    // On clear l'ecran
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // pour utiliser un shader (pour que ce soit ce dernier qui dessine la geometrie) il faut le binder.
      // Un seul shader peut etre actif en meme temps

  if (_texture.load("./srcs/ground.tga") == false)
    {
      std::cerr << "Cannot load the ground texture" << std::endl;
      //return (false);
    }
  //  _geometry.setColor(glm::vec4(1, 0, 0, 1));

  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(80, 0, 0));
  _geometry.pushVertex(glm::vec3(80, 50, 0));
  _geometry.pushVertex(glm::vec3(0, 50, 0));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));

  _geometry.build();

  _texture.bind();
  _geometry.draw(_shader, getTransformation(), GL_QUADS);

      /*
      (map)
      objet depuis factory
      draw objet
      supprime objet
      */

    // _blockFactory.init_map();
    /*    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->draw(_shader, _clock);

      // On met ensuite a jour l'ecran pour que ce que l'on a dessine s'affiche*/
    _context.flush();
}

GameEngine::~GameEngine()
{
  // N'oublions pas de supprimer les objets une fois le programme termine!
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
}
