#include "Monster.hh"

bool Monster::win() {
  return this->position == targetPosition;
}

Monster::Monster() {
  cannotWalkOn = {'o', '*', 'M', 'm'};
}
