#include "NotSoDumbMonster.hh"

NotSoDumbMonster::NotSoDumbMonster(Position p) {
  position = Position(p.getX(), p.getY());
  symbole = 'M';
  deplacement = 1;
}

void NotSoDumbMonster::move(std::vector<bool> availableMoves) {
  if (availableMoves[0] && targetPosition.getY() < position.getY()) {
    position = position +  Position(0, -deplacement);
  } else if (availableMoves[1] && targetPosition.getY() > position.getY()) {
    position = position +  Position (0, deplacement);
  } else if (availableMoves[2] && targetPosition.getX() < position.getX()){
    position = position +  Position(-deplacement, 0);
  } else if (availableMoves[3] && targetPosition.getX() > position.getX()) {
    position = position +  Position(deplacement, 0);
  } else if (availableMoves[4] && targetPosition.getY() < position.getY()) {
    position = position +  Position(-deplacement, -deplacement);
  } else if (availableMoves[5] && targetPosition.getY() > position.getY()) {
    position = position +  Position (-deplacement, deplacement);
  } else if (availableMoves[6] && targetPosition.getX() < position.getX()){
    position = position +  Position(deplacement, deplacement);
  } else if (availableMoves[7] && targetPosition.getX() > position.getX()) {
    position = position +  Position(deplacement, -deplacement);
  }
}
