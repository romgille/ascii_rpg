#include "thune.hh"

Thune::Thune() {
  this->symbole = '$';
  this->position = Position();
}

Thune::Thune(Position p) {
  this->symbole = '$';
  this->position = p;
}
