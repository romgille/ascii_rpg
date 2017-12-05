#ifndef TARGET_HH
#define TARGET_HH

#include <memory>

#include "ImmobileObject.hh"
#include "Position.hh"

class Target : public ImmobileObject {

public:
  Target(Position p);
  Target();
  ~Target() = default;
  char symbole = 'T';
};

#endif /* end of include guard: TARGET_HH */
