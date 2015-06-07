//
// Created by navarr_a on 06/06/15.
//

#ifndef __CHARACTER_HH__
#define __CHARACTER_HH__

class Character
{
public:
  Character();
  Character(Character const &);
  virtual ~Character() {}
  Character &operator=(Character const &);
protected:

};

#endif /* __CHARACTER_HH__ */