#ifndef __BLOCKFACTORY_HH__
# define __BLOCKFACTORY_HH__

// // #include <iostream>
// #include <string>
// #include <map>
// #include "Solid.hh"
#include "AObject.hh"
#include "Solid.hh"
#include "Break.hh"
#include "Player.hh"
#include "Bot.hh"
#include "Map.hh"

// template <class Object,class Key=string> class Factory
// {
//   static std::map<Key,Object*> m_map;
// public:

//   static void Register(Key key,Object* obj);
//   Object* Create(const Key& key);
// };

class BlockFactory
{
public:
  BlockFactory();
  ~BlockFactory();
  BlockFactory(BlockFactory const &);
  BlockFactory &operator=(BlockFactory const &);

  AObject *createInstance(Map::status);
  // template<typename T> AObject* createInstance(Map::status) {  return new T; }
  // // AObject* getInstance(int);
  // // void init_map();

// private:
  // std::map<int, > _map;
};

#endif /* !__BLOCKFACTORY_HH__ */
