#include "Rock.hh"

Rock::Rock(Position p) {
  position = Position(p.getX(), p.getY());
  symbole = 'o';
}
