#ifndef ROCK_HH
#define ROCK_HH

#include "ImmobileObject.hh"

class Rock : public ImmobileObject {
public:
  Rock(Position p);
  ~Rock() = default;
};

#endif /* end of include guard: ROCK_HH */
