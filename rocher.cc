#include "rocher.hh"

Rocher::Rocher() {
  this->symbole = 'o';
  this->position = Position();
}

Rocher::Rocher(Position p) {
  this->symbole = 'o';
  this->position = p;
}
