#ifndef MONSTER_HH
#define MONSTER_HH

#include <vector>

#include "Position.hh"
#include "MovableObject.hh"

class Monster : public MovableObject {
public:
  Position position;
  char symbole;
  bool win();
  virtual void move(std::vector<bool> availableMoves) = 0;
  ~Monster() = default;

protected:
  Position targetPosition;
};

#endif
