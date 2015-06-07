//
// Created by navarr_a on 06/06/15.
//

#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include "Character.hh"

class Player : public Character
{
public:
  Player();
  Player(Player const&);
  virtual ~Player() {}
  Player &operator=(Player const &);
protected:
};

#endif /* __PLAYER_HH__ */
