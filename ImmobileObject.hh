#ifndef IMMOBILEOBJECT_HH
#define IMMOBILEOBJECT_HH

#include "Position.hh"

class ImmobileObject {

public:
  Position position;
  char symbole = ' ';

  ~ImmobileObject() = default;
};

#endif
