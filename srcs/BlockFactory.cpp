#include "BlockFactory.hh"

BlockFactory::BlockFactory()
{

}

BlockFactory::~BlockFactory()
{

}

BlockFactory::BlockFactory(BlockFactory const &c)
{
  (void)c;
}

BlockFactory	&BlockFactory::operator=(BlockFactory const &c)
{
  if (this != &c)
    {

    }
  return (*this);
}

AObject *BlockFactory::createInstance(Map::status status)
{
  if (status == Map::SOLID)
    return (new Solid());
  if (status == Map::BREAK)
    return (new Break());
  if (status == Map::P1 || status == Map::P2)
    return (new Player());
  return (NULL);
}
// void BlockFactory::init_map() {
//   _map[0] = &createInstance<Groud>;
// }

// AObject*   BlockFactory::getInstance(int status){
//   AObject* ptr = 0;
//   if (_map[status])
//     ptr = _map[status]();
//   return (ptr);
// }
