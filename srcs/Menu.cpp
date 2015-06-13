#include "Menu.hh"

Menu::Menu()
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

int			Menu::eventHandler()
{
  /* gestion des events sur la page play */

  /* si on catch click souris sur le bouton "Menu" */
  int		playerInput = 2;
  //if ()
  //player input = 2
  int		botInput = 10; /* récupère input nb bots */
<<<<<<< Updated upstream
  int		xMap = 30; /* récupère input x de la map */
  int		yMap = 20; /* récupère input y de la map */

=======
  int		xMap = 80; /* récupère input x de la map */
  int		yMap = 50; /* récupère input y de la map */
>>>>>>> Stashed changes
  Map		map(xMap, yMap, playerInput, botInput);

  if (map.getWidth() < 10 || map.getHeight() < 10 || map.setRandomMap() == 1)
    return (1);
  // Kill la fenêtre de menu à coder
  map.showMap();
  run(map);
  /* --------------------------------------------- */
  return (0);
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

bool			Menu::showMenu()
{
  if (!_context.start(800, 600, "Intro"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER)
	 || !_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER)
	 || !_shader.build())
    return false;
  _shader.bind();
  _speed = 20.0f;
  std::cout << "start intro" << std::endl;
  if (_texture.load("./img/Main.tga") == false)
  {
    std::cerr << "Cannot load Main.tga" << std::endl;
    return (false);
  }
  rotate(glm::vec3(0, 0, 5), -90);
  _geometry.pushVertex(glm::vec3(19, -19, 34));
  _geometry.pushVertex(glm::vec3(19, 19, 34));
  _geometry.pushVertex(glm::vec3(-19, 19, 19));
  _geometry.pushVertex(glm::vec3(-19, -19, 19));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  translate(glm::vec3(-15, 0.2, 0));
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
