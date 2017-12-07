#ifndef FELLOW_HH
#define FELLOW_HH

#include <vector>

#include "Position.hh"
#include "MovableObject.hh"

class Fellow : public MovableObject {
public:
  Fellow(Position p);
  ~Fellow() = default;
  bool win();
  bool winner = false;
  void move(std::vector<bool> availableMoves);
};

#endif
