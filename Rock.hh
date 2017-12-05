#ifndef ROCK_HH
#define ROCK_HH

#include "ImmobileObject.hh"

class Rock : public ImmobileObject {
public:
  char symbole = 'o';
  Rock(Position p);
  ~Rock() = default;
};

#endif /* end of include guard: ROCK_HH */
