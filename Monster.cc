#include "Monster.hh"

bool Monster::win() {
  return this->position == targetPosition;
}
