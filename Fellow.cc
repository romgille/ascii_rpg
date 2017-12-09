#include <iostream>

#include "Fellow.hh"

bool Fellow::win() {
  return position == targetPosition || winner;
}

Fellow::Fellow(Position p) {
  position = Position(p.getX(), p.getY());
  symbole = 'i';
  deplacement = 1;
  cannotWalkOn = {'m', 'o', 'M'};
  //objectives.push_back();
  potionTaken = false;
}

Fellow::Fellow(Position p, std::vector<Objective> o) {
  position = Position(p.getX(), p.getY());
  symbole = 'i';
  deplacement = 1;
  cannotWalkOn = {'m', 'o', 'M'};
  objectives = o;
  potionTaken = false;
}

void Fellow::move(std::vector<bool> availableMoves) {
  if (availableMoves[0] == 1 && targetPosition.getX() < position.getX()) {
    position = position +  Position(-deplacement, 0);
    //std::cout << "i : move up" << std::endl;
  } else if (availableMoves[1] == 1 && targetPosition.getX() > position.getX()) {
    position = position +  Position (deplacement, 0);
    //std::cout << "i : move down" << std::endl;
  } else if (availableMoves[2] == 1 && targetPosition.getY() > position.getY()){
    position = position +  Position(0, +deplacement);
    //std::cout << "i : move right" << std::endl;
  } else if (availableMoves[3] == 1 && targetPosition.getY() < position.getY()) {
    position = position +  Position(0, -deplacement);
    //std::cout << "i : move left" << std::endl;
  } else {
    //std::cout << "i : can't move" << std::endl;
  }
}
