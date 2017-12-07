#include "DumbMonster.hh"

DumbMonster::DumbMonster(Position p) {
  position = Position(p.getX(), p.getY());
  symbole = 'm';
  deplacement = 1;
}

void DumbMonster::move(std::vector<bool> availableMoves) {
  if (availableMoves[0] && targetPosition.getY() < position.getY()) {
    position = position +  Position(0, -deplacement);
  } else if (availableMoves[1] && targetPosition.getY() > position.getY()) {
    position = position +  Position (0, deplacement);
  } else if (availableMoves[2] && targetPosition.getX() < position.getX()){
    position = position +  Position(-deplacement, 0);
  } else if (availableMoves[3] && targetPosition.getX() > position.getX()) {
    position = position +  Position(deplacement, 0);
  }
}
