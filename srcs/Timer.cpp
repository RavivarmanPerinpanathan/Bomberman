#include "Timer.hh"

Timer::Timer(Map &map)
  : _map(map)
{

}

Timer::~Timer()
{

}

Timer::Timer(Timer const &c)
  : _map(c._map)
{
  std::cout << "in modif" << std::endl;
}

Timer	&Timer::operator=(Timer const &c)
{
  if (this != &c)
    {
      std::cout << "in modif" << std::endl;
      _map = c._map;
    }
  return (*this);
}

void	Timer::launch()
{
  pthread_t	thr;

  std::cout << "in thread" << std::endl;
  pthread_create(&thr, NULL, &countdown, this);
  std::cout << "out thread" << std::endl;
  _map.showMap();
}

void	*Timer::countdown(void *param)
{
  sleep(3);
  ((Timer*)param)->explosion();
  return (NULL);
}

void	Timer::explosion()
{
  _map.showMap();
}
