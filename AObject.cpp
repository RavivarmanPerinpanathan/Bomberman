#include "AObject.hh"

AObject::AObject() :
  _position(0, 0, 0), // On initialise la position a 0
  _rotation(0, 0, 0), // pareil pour la rotation
  _scale(1, 1, 1) // l'echelle est mise a 1
{
}

AObject::~AObject()
{

}

bool AObject::initialize()
{
  return true;
}

void AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4 AObject::getTransformation()
{
  glm::mat4 transform(1); // On cree une matrice identite
  // On applique ensuite les rotations selon les axes x, y et z

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  // On effectue ensuite la translation
   transform = glm::translate(transform, _position);
  // Et pour finir, on fait la mise a l'echelle
  transform = glm::scale(transform, _scale);
  return (transform);
}
