#ifndef TARGET_HH
#define TARGET_HH

#include <memory>

#include "Objective.hh"
#include "Position.hh"

class Target : public Objective {

public:
  Target(Position p);
  Target();
  ~Target() = default;
};

#endif /* end of include guard: TARGET_HH */
