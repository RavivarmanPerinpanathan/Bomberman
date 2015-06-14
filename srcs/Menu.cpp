#include "Menu.hh"

Menu::Menu()
: _playerInput(2), _botInput(5), _xMap(30), _yMap(20), _speed(0.07), _time(0.0)
{
}

Menu::~Menu()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
}

Menu::Menu(Menu const &c)
{
  (void)c;
}

Menu			&Menu::operator=(Menu const &c)
{
  if (this != &c)
    {
    }
  return (*this);
}


bool			Menu::initialize()
{
  if (!_context.start(1024, 768, "Menu"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER)
	 || !_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER)
	 || !_shader.build())
    return false;
  _shader.bind();

  if (_texture.load("./img/Menu_back2.tga") == false)
  {
    std::cerr << "Cannot load Menu_back.tga" << std::endl;
    return (false);
  }
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(260, 0, 0));
  _geometry.pushVertex(glm::vec3(260, 200, 0));
  _geometry.pushVertex(glm::vec3(0, 200, 0));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));

  _geometry.build();
  _projection = glm::perspective(50.0f, 1024.0f / 768.0f, 0.1f, 2000.0f);
  return true;
}

bool			Menu::update()
{
  _context.updateInputs(_input);
  glm::ivec2 mouse;
  bool		created;

  if (_input.getKey(SDLK_ESCAPE))
    return (false);
  if (_time > _speed)
    {
      created = false;
      if (_input.getKey(SDL_BUTTON_LEFT))
	{
	  mouse = _input.getMousePosition();
	  if (mouse.x < (WIDTH / 2) - 20 && mouse.y < (HEIGHT / 4) - 40)
	    {
	      std::cout << "One player mode !" << std::endl;
	      _playerInput = 1;
	    }
	  if (mouse.x < (WIDTH / 2) - 20 &&
	      (mouse.y > (HEIGHT / 4) - 40 && mouse.y < (HEIGHT / 8) + (HEIGHT / 4) - 40))
	    {
	      std::cout << "Two players mode !" << std::endl;
	      _playerInput = 2;
	    }
	  if (mouse.x < (WIDTH / 2) - 20 &&
	      (mouse.y > (HEIGHT / 8) + (HEIGHT / 4) - 40 && mouse.y < (HEIGHT / 2) - 40))
	    {
	      if (mouse.x < (WIDTH / 4) - 20)
		_botInput -= 1;
	      else
		_botInput += 1;
	      std::cout << "Bots = " << _botInput << std::endl;
	    }
	  if (mouse.x < (WIDTH / 2) - 20 &&
	      (mouse.y > (HEIGHT / 2) - 40 && mouse.y < (HEIGHT / 2) + HEIGHT / 8 - 40))
	    {
	      if (mouse.x < (WIDTH / 4) - 20)
		_xMap -= 1;
	      else
		_xMap += 1;
	    std::cout << "X map = " << _xMap << std::endl;
	    }
	  if (mouse.x < (WIDTH / 2) - 20 && (mouse.y > (HEIGHT / 2) + HEIGHT / 8 - 35) &&
	    mouse.y < (HEIGHT / 2 + HEIGHT / 4)) {
	    if (mouse.x < (WIDTH / 4) - 20)
	      _yMap -= 1;
	    else
	      _yMap += 1;
	    std::cout << "Y map = " << _yMap << std::endl;
	  }
	  if (mouse.x<(WIDTH / 2) - 20 && mouse.y>(HEIGHT / 2 + HEIGHT / 4)) {
	    if (created == false)
	      {
		created = true;
		Map map(_xMap, _yMap, _playerInput, _botInput);

		if (map.getWidth() < 10 || map.getHeight() < 10 || map.setRandomMap() == 1)
		  return (1);
		_context.stop();
		std::cout << "run" << std::endl;
		if (run(map) == EXIT_SUCCESS)
		  return (false);
		std::cout << "out" << std::endl;
	      }
	  }
	}
      _time = 0;
    }
  _time += _clock.getElapsed();
  _context.updateClock(_clock);
  _transformation = glm::lookAt(glm::vec3(790, 560, -1200), glm::vec3(790, 560, 0), glm::vec3(0, 1, 0));
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);
  return (true);
}

int			Menu::run(Map map)
{
  GameEngine engine(map);

  if (engine.initialize() == false)
    return (EXIT_FAILURE);
  while (engine.update()!=false)
    engine.draw();
  return (EXIT_SUCCESS);
}
void Menu::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _texture.bind();
  _geometry.draw(_shader, getTransformation(), GL_QUADS);
  _shader.bind();
  _context.flush();
}

glm::mat4 Menu::getTransformation()
{
  glm::mat4 transform(1);
  transform = glm::scale(transform, glm::vec3(6, 6, 0));
  return (transform);
}
