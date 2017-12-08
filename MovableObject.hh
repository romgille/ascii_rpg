#ifndef MOVABLEOBJECT_HH
#define MOVABLEOBJECT_HH

#include "Position.hh"
#include "Object.hh"
#include <vector>

class MovableObject : public Object {
public:
  void move(std::vector<bool> availableMoves);
  ~MovableObject() = default;
  std::vector<char> cannotWalkOn;
};

#endif /* end of include guard: MOVABLEOBJECT_HH */
