#ifndef POTION_HH
#define POTION_HH

#include "Objective.hh"

class Potion : public Objective {
public:
  Potion(Position p);
  ~Potion() = default;
};

#endif /* end of include guard: POTION_HH */
