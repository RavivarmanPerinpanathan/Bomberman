//
// Created by navarr_a on 06/06/15.
//

#ifndef __BOT_HH__
#define __BOT_HH__

#include "Character.hh"

class Bot : public Character
{
  public:
    Bot();
    Bot(Bot const&);
    virtual ~Bot() {}
    Bot &operator=(Bot const &);
  protected:
};
#endif /* __BOT_HH__ */
