#ifndef __EXPLOSION_HH__
# define __EXPLOSION_HH__

#include <iostream>
#include <string>

class Explosion
{
public:
  Explosion()
  ~Explosion()
  Explosion(Explosion const &);
  Explosion &operator=(Explosion const &);
};

#endif /* !__EXPLOSION_HH__ */
