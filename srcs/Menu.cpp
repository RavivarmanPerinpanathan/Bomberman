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
      //
    }
  return (*this);
}

int			Menu::eventHandler(gdl::Input &input)
{
  glm::ivec2 mouse;
  /* gestion des events sur la page play */
  (void)input;
  /* si on catch click souris sur le bouton "Menu" */
   mouse = input.getMousePosition();
  //std::cout << mouse << std::endl;
  // if (input.getKey(SDLK_LEFT))
  //   playerInput = 2;

  run(map);
  /* --------------------------------------------- */
  return (0);
}

int			Menu::run(Map map)
{
  if (initialize() == false)
    return (EXIT_FAILURE);
  while (eventHandler()!=false)
    draw();
  return (EXIT_SUCCESS);
}

bool			Menu::initialize()
{
  std::cout << "hello" << std::endl;
  if (!_context.start(800, 600, "Intro"))
    return false;
  std::cout << "hello" << std::endl;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER)
	 || !_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER)
	 || !_shader.build())
    return false;
  _shader.bind();
  return true;
}

void Menu::draw()
{
  // On clear l'ecran
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // pour utiliser un shader (pour que ce soit ce dernier qui dessine la geometrie) il faut le binder.
  // Un seul shader peut etre actif en meme temps
  _shader.bind();
  // On dessine tous les objets composant la scene
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  // On met ensuite a jour l'ecran pour que ce que l'on a dessine s'affiche
  _context.flush();
}
bool			Menu::showMenu()
{
  _speed = 20.0f;
  std::cout << "start intro" << std::endl;
  if (_texture.load("./img/Main.tga") == false)
  {
    std::cerr << "Cannot load Main.tga" << std::endl;
    return (false);
  }
 // rotate(glm::vec3(0, 0, 5), -90);
  _geometry.pushVertex(glm::vec3(19, -19, 34));
  _geometry.pushVertex(glm::vec3(19, 19, 34));
  _geometry.pushVertex(glm::vec3(-19, 19, 19));
  _geometry.pushVertex(glm::vec3(-19, -19, 19));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  //translate(glm::vec3(-15, 0.2, 0));
  _geometry.build();
  std::cout << "end intro" << std::endl;
  return (true);
  /* affichage de la page play */
  //eventHandler();

  /*
   * Mettre dans le .hh les variables (y'a déjà _object)
   * Copier les Game engine pour qu'il affiche bien le menu
   * Faire les touches dans le eventHandler()
   * Quand tout est bon (la map crée avec les input) il faut faire un context.stop()
   */
}


