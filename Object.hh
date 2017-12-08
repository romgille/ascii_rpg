#ifndef OBJECT_HH
#define OBJECT_HH

#include "Position.hh"

class Object {
public:
  Position targetPosition;
  int deplacement;
  Position position;
  char symbole;
};

#endif
