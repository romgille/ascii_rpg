#ifndef FELLOW_HH
#define FELLOW_HH

#include <vector>

#include "Position.hh"
#include "MovableObject.hh"

class Fellow : public MovableObject {
public:
  Fellow(Position p);
  Fellow(Position p, std::vector<Objective> o);
  ~Fellow() = default;
  std::vector<Objective> objectives;
  bool potionTaken;
  bool win();
  bool winner = false;
  void move(std::vector<bool> availableMoves);
};

#endif
