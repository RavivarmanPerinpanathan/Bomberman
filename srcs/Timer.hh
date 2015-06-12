#ifndef __TIMER_HH__
# define __TIMER_HH__

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include "Map.hh"

class Timer
{
public:
  Timer(Map &);
  ~Timer();
  Timer(Timer const &);
  Timer &operator=(Timer const &);

  void		launch();
  static void	*countdown(void *);
  void		explosion();

protected:
  Map		_map;
};


#endif /* !__TIMER_HH__ */
