#include "position.hh"
#include <iostream>


Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

Position::Position() {
  this->x = 0;
  this->y = 0;
}

void Position::move(int alpha, int beta) {
    this->x += alpha;
    this->y += beta;
}

void Position::print(){
  std::cout << "x : " << x << " y : " << y << std::endl;
}
