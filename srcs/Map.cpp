#include "Map.hh"

Map::Map(int width, int height)
  : _width(width), _height(height);
{

}

Map::~Map()
{

}

Map::Map(Map const &c)
  : _width(c._width), _height(c._height)
{

}

Map		&Map::operator=(Map const &c)
{
  if (this != &c)
    {
      _width = c._width;
      _height = c._height;
    }
  return (*this);
}

int		Map::getWidth() const
{
  return (_width);
}

int		Map::getHeight() const
{
  return (_height);
}

std::map<std::pair<int, int>, Map::status>	&Map::getMap()
{
  return (_map);
}
