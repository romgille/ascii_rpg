#ifndef FELLOW_HH
#define FELLOW_HH

#include <vector>

#include "Position.hh"
#include "MovableObject.hh"

class Fellow : public MovableObject {
private:
  Position targetPosition;

public:
  Fellow(Position p);
  ~Fellow() = default;
  bool win();
  bool winner = false;
  char symbole = 'i';
  int deplacement = '1';
  void move(std::vector<bool> availableMoves);
};

#endif
