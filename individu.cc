#include "individu.hh"

Individu::Individu() {
    this->symbole = 'i';
    this->deplacement = 1;
    this->position = Position();
}

Individu::Individu(Position p) {
    this->symbole = 'i';
    this->deplacement = 1;
    this->position = p;
}
