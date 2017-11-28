#include "monstre_pas_con.hh"

MonstrePasCon::MonstrePasCon() {
    this->symbole = 'M';
    this->deplacement = 2;
    this->position = Position();
}

MonstrePasCon::MonstrePasCon(Position p) {
    this->symbole = 'M';
    this->deplacement = 2;
    this->position = p;
}
