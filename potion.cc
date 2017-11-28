#include "potion.hh"

Potion::Potion() {
  this->symbole = '*';
  this->position = Position();
}

Potion::Potion(Position p) {
  this->symbole = '*';
  this->position = p;
}
