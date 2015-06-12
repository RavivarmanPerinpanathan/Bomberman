#ifndef __BLOCK_HH__
# define __BLOCK_HH__

#include <iostream>
#include <string>
#include <Geometry.hh>
#include <Texture.hh>
#include "AObject.hh"

class Block : public AObject
{
public:
  draw(Shader &, gdl::Clock &);
}
