#include "monstre_con.hh"

MonstreCon::MonstreCon() {
    this->symbole = 'm';
    this->deplacement = 1;
    this->position = Position();
}

MonstreCon::MonstreCon(Position p) {
    this->symbole = 'm';
    this->deplacement = 1;
    this->position = p;
}
