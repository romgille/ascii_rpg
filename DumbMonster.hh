#ifndef DUMBMONSTER_HH
#define DUMBMONSTER_HH

#include <vector>

#include "Monster.hh"
#include "Position.hh"

class DumbMonster : public Monster {
public:
  DumbMonster(Position p);
  ~DumbMonster() = default;
  void move(std::vector<bool> availableMoves);
};

#endif /* end of include guard: DUMBMONSTER_HH */
