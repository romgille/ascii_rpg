#ifndef OBJECTIVE_HH
#define OBJECTIVE_HH

#include "ImmobileObject.hh"

class Objective : public ImmobileObject {

  public:
    Objective(Position p);
    ~Objective() = default;
};

#endif /* end of include guard: OBJECTIVE_HH */
