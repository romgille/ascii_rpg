#ifndef MOVABLEOBJECT_HH
#define MOVABLEOBJECT_HH

#include "Position.hh"
#include <vector>

class MovableObject {
public:
  Position position;
  Position targetPosition;
  int deplacement;
  char symbole;

  void move(std::vector<bool> availableMoves);

  ~MovableObject() = default;
};

#endif /* end of include guard: MOVABLEOBJECT_HH */
