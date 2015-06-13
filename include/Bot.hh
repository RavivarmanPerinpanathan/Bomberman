#ifndef __BOT_HH__
# define __BOT_HH__

#include <iostream>
#include <string>

class Bot
{
public:
  Bot();
  ~Bot();
  Bot(Bot const &);
  Bot	&operator=(Bot const &);

  std::pair<int, int>	getPos() const;
  void			setPos(std::pair<int, int>);

protected:
  std::pair<int, int>	_pos;
};

#endif /* !__BOT_HH__ */
