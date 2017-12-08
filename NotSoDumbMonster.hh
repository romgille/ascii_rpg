#ifndef NOTSODUMBMONSTER_HH
#define NOTSODUMBMONSTER_HH

#include <vector>

#include "Monster.hh"
#include "Position.hh"

class NotSoDumbMonster : public Monster {
public:
  NotSoDumbMonster(Position p);
  ~NotSoDumbMonster() = default;
  void move(std::vector<bool> availableMoves);
};

#endif /* end of include guard: NOTSODUMBMONSTER_HH */
