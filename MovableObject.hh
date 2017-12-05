#ifndef MOVABLEOBJECT_HH
#define MOVABLEOBJECT_HH

#include "Position.hh"

class MovableObject {
public:
  Position position;
  int deplacement;
  void move(std::vector<bool> availableMoves);

  ~MovableObject() = default;
};

#endif /* end of include guard: MOVABLEOBJECT_HH */
