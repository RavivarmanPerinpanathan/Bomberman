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
  if (status == 0)
    return (new Solid());
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
