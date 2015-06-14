#include "Menu.hh"

Menu::Menu()
: _playerInput(2), _botInput(10), _xMap(30), _yMap(20)
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
  if (_texture.load("./img/Main.tga") == false)
  {
    std::cerr << "Cannot load Main.tga" << std::endl;
    return (false);
  }
  _geometry.pushVertex(glm::vec3(19, -19, 34));
  _geometry.pushVertex(glm::vec3(19, 19, 34));
  _geometry.pushVertex(glm::vec3(-19, 19, 19));
  _geometry.pushVertex(glm::vec3(-19, -19, 19));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();

  _projection = glm::perspective(50.0f, 1600.0f / 800.0f, 0.1f, 100.0f);
  _transformation = glm::lookAt(glm::vec3(0, 20, 50), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.setUniform("view", _transformation);
  _shader.setUniform("projection", _projection);
  return true;
}

bool			Menu::update()
{
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  glm::ivec2 mouse;
  mouse = _input.getMousePosition();
   if (_input.getKey(SDLK_ESCAPE))
     return (false);
  std::cout << mouse.x << std::endl;
  std::cout << mouse.y << std::endl;

  /* --------------------------------------------- */
  return (true);
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
  transform = glm::scale(transform, glm::vec3(20, 20, 1));
  return (transform);
}
