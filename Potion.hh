#ifndef POTION_HH
#define POTION_HH

#include "ImmobileObject.hh"

class Potion : public ImmobileObject {
public:
  Potion(Position p);
  ~Potion() = default;
};

#endif /* end of include guard: POTION_HH */
