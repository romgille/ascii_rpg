#include "Money.hh"

Money::Money(Position p) {
  position = Position(p.getX(), p.getY());
  symbole = '$';
}
