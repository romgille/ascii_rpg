#include "position.hh"


Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

void Position::move(int alpha, int beta) {
    this->x += alpha;
    this->y += beta;
}