#include "objectif.hh"

Objectif::Objectif() {
  this->symbole = 'T';
  this->position = Position();
}

Objectif::Objectif(Position p) {
  this->symbole = 'T';
  this->position = p;
}
