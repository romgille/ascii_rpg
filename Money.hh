#ifndef MONEY_HH
#define MONEY_HH

#include "ImmobileObject.hh"

class Money : public ImmobileObject {
public:
  Money(Position p);
  ~Money() = default;
};

#endif /* end of include guard: MONEY_HH */
