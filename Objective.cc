#include "Objective.hh"

Objective::Objective(Position p, char s) {
  position = Position(p.getX(), p.getY());
  symbole = s;
}
