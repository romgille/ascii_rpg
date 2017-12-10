#include "NotSoDumbMonster.hh"
#include <iostream>

NotSoDumbMonster::NotSoDumbMonster(Position p) {
  position = Position(p.getX(), p.getY());
  symbole = 'M';
  deplacement = 1;
}

void NotSoDumbMonster::move(std::vector<bool> availableMoves) {
  if (availableMoves[0] == 1 && targetPosition.getX() < position.getX()) {
    position = position + Position(-deplacement, 0);
    //std::cout << "i : move up" << std::endl;
  } else if (availableMoves[1] == 1 && targetPosition.getX() > position.getX()) {
    position = position + Position(deplacement, 0);
    //std::cout << "i : move down" << std::endl;
  } else if (availableMoves[2] == 1 && targetPosition.getY() > position.getY()){
    position = position + Position(0, +deplacement);
    //std::cout << "i : move right" << std::endl;
  } else if (availableMoves[3] == 1 && targetPosition.getY() < position.getY()) {
    position = position + Position(0, -deplacement);
    //std::cout << "i : move left" << std::endl;
  } else {
    //std::cout << "i : can't move" << std::endl;
  }
}
