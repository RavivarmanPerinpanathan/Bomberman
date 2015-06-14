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

  // button Player 1
  if (_texture2.load("./img/ground.tga") == false)
  {
    std::cerr << "Cannot load Player1.tga" << std::endl;
    return (false);
  }
  // _geometry2.pushVertex(glm::vec3(0, 0, 0));
  // _geometry2.pushVertex(glm::vec3(0, 0, 1));
  // _geometry2.pushVertex(glm::vec3(0, 1, 1));
  // _geometry2.pushVertex(glm::vec3(0, 1, 0));
  _geometry2.pushVertex(glm::vec3(0.25, -0.25, 0.25));
  _geometry2.pushVertex(glm::vec3(0.25, 0.25, 1));
  _geometry2.pushVertex(glm::vec3(-0.25, 1, 1));
  _geometry2.pushVertex(glm::vec3(-0.25, -1, 0.25));
  
  _geometry2.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry2.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry2.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry2.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry2.build();

  //background image
  if (_texture.load("./img/ground.tga") == false)
  {
    std::cerr << "Cannot load Menu_back.tga" << std::endl;
    return (false);
  }
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushVertex(glm::vec3(1024, 768, 0));
  _geometry.pushVertex(glm::vec3(1024, 0, 0));
  _geometry.pushVertex(glm::vec3(0, 768, 0));
  
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));


  _geometry.build();

  _projection = glm::perspective(50.0f, 1024.0f / 728.0f, 0.1f, 1000.0f);
  _transformation = glm::lookAt(glm::vec3(0, 0, 700), glm::vec3(40, 60, 0), glm::vec3(0, 1, 0));
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
  //  _position = glm::vec3(0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _texture.bind();
  _geometry.draw(_shader, getTransformation(), GL_QUADS);
  //  _texture2.bind();
  // _geometry2.draw(_shader, getTransformation(), GL_QUADS);
  _shader.bind();
  _context.flush();
}
glm::mat4 Menu::getTransformation()
{
  glm::mat4 transform(1);
  transform = glm::scale(transform, glm::vec3(20, 20, 0));
  return (transform);
}
