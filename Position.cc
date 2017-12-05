#include "Position.hh"

Position::Position(int x_, int y_) {
  x = x_;
  y = y_;
}

Position::Position() {
  x = 0;
  y = 0;
}

int Position::getX() {
  return x;
}

void Position::setX(int x_) {
  x = x_;
}

int Position::getY() {
  return y;
}

void Position::setY(int y_) {
  y = y_;
}

bool Position::operator==(Position p){
  return x == p.x && y == p.y;
}

Position Position::operator+(Position p){
  return Position(x + p.x, y + p.y);
}
