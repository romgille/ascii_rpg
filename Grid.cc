#include "Grid.hh"
#include <algorithm>

Grid::Grid(std::string data[]) {
  map.resize(size);
  for (size_t i = 0; i < size; ++i){
    map[i].resize(size);
    for (size_t j = 0; j < size; ++j){
      switch (data[i][j]) {
        case 'i':
        fellows.push_back(std::make_unique<Fellow>(Position(i, j)));
        map[i][j] = data[i][j];
        break;
        case 'T':
        immobileObjects.push_back(std::make_unique<Target>(Position(i, j)));
        map[i][j] = data[i][j];
        break;
        case 'm':
        monsters.push_back(std::make_unique<DumbMonster>(Position(i, j)));
        map[i][j] = data[i][j];
        break;
        case 'o':
        immobileObjects.push_back(std::make_unique<Rock>(Position(i, j)));
        map[i][j] = data[i][j];
        break;
        case '*':
        immobileObjects.push_back(std::make_unique<Potion>(Position(i, j)));
        hasPotion = true;
        map[i][j] = data[i][j];
        break;
        case 'M':
        monsters.push_back(std::make_unique<NotSoDumbMonster>(Position(i, j)));
        map[i][j] = data[i][j];
        break;
        case '$':
        immobileObjects.push_back(std::make_unique<Money>(Position(i, j)));
        hasMoney = true;
        map[i][j] = data[i][j];
        break;
        default:
        map[i][j] = ' ';
        break;
      }
    }
  }
}

bool Grid::monstersWin() {
  if (monsters.size() == 0) return false;

  for (size_t i = 0; i < monsters.size(); ++i) {
    if (!monsters[i]->win()){
      return false;
    }
  }
  return true;
}

bool Grid::fellowsWin() {
  if (fellows.size() == 0) return false;

  for (size_t i = 0; i < fellows.size(); ++i) {
    if (!fellows[i]->win()){
      return false;
    }
  }
  return true;
}

void Grid::displayMap() {
  std::cout << "\"";
  for(size_t i = 0; i < size; ++i){
    for(size_t j = 0; j < size; ++j){
      std::cout << map[i][j];
    }
    std::cout << "\"," << std::endl;
    std::cout << "\"";
  }
  std::cout << std::endl;
}

std::vector<bool> Grid::availableMoves(MovableObject& movable) {
  bool north = true;
  bool south = true;
  bool east = true;
  bool west = true;
  bool northE = true;
  bool southE = true;
  bool northW = true;
  bool southW = true;

  if (movable.position.getX() - movable.deplacement >= 0) {
    auto goNorth = std::find(
      std::begin(movable.cannotWalkOn),
      std::end(movable.cannotWalkOn),
      map[movable.position.getX() - movable.deplacement][movable.position.getY()]
    );

    if (goNorth != std::end(movable.cannotWalkOn)) north = false;
  }

  if (movable.position.getX() + movable.deplacement < size) {
    auto goSouth = std::find(
      std::begin(movable.cannotWalkOn),
      std::end(movable.cannotWalkOn),
      map[movable.position.getX() + movable.deplacement][movable.position.getY()]
    );

    if (goSouth != std::end(movable.cannotWalkOn)) south = false;
  }

  if (movable.position.getY() + movable.deplacement < size) {
    auto goEast = std::find(
      std::begin(movable.cannotWalkOn),
      std::end(movable.cannotWalkOn),
      map[movable.position.getX()][movable.position.getY() + movable.deplacement]
    );

    if (goEast != std::end(movable.cannotWalkOn)) east = false;
  }
  if (movable.position.getY() - movable.deplacement >= 0) {
    auto goWest = std::find(
      std::begin(movable.cannotWalkOn),
      std::end(movable.cannotWalkOn),
      map[movable.position.getX()][movable.position.getY() - movable.deplacement]
    );

    if (goWest != std::end(movable.cannotWalkOn)) west = false;
  }

  std::vector<bool> availablesMoves = {north, south, east, west, northW, southW, southE, northE};
  return availablesMoves;
}

void Grid::update() {
  Position potionPosition;
  int potionIndex;
  Position moneyPosition;
  Position targetPosition;

  // remove all elements from map
  for(size_t i = 0; i < map.size(); ++i){
    for(size_t  j = 0; j < map.size(); ++j){
      map[i][j] = ' ';
    }
  }

  // add immobileObjects to map
  for (size_t i = 0; i < immobileObjects.size(); ++i){
    map[immobileObjects[i]->position.getX()][immobileObjects[i]->position.getY()] = immobileObjects[i]->symbole;
    if (immobileObjects[i]->symbole == '*') {
      potionPosition = Position(immobileObjects[i]->position.getX(), immobileObjects[i]->position.getY());
      potionIndex = i;
    }
    if (immobileObjects[i]->symbole == '$') {
      moneyPosition = Position(immobileObjects[i]->position.getX(), immobileObjects[i]->position.getY());
    }
    if (immobileObjects[i]->symbole == 'T') {
        targetPosition = Position(immobileObjects[i]->position.getX(), immobileObjects[i]->position.getY());
    }
  for (size_t i = 0; i < fellows.size(); ++i){
    // add fellow to map
    map[fellows[i]->position.getX()][fellows[i]->position.getY()] = fellows[i]->symbole;
      for (size_t j = 0; j < monsters.size(); ++j){
        monsters[i]->targetPosition = Position(fellows[i]->position.getX(), fellows[i]->position.getY());
      }

    // special cases for fellow
    if (Position(fellows[i]->position.getX(), fellows[i]->position.getY()) == potionPosition) {
      fellows[i]->deplacement = 2;
      immobileObjects.erase(immobileObjects.begin() + potionIndex);
      hasPotion = false;
    }
    if (Position(fellows[i]->position.getX(), fellows[i]->position.getY()) == moneyPosition) {
      fellows[i]->winner = true;
    }
  }
  if (potionPosition.getX() != 0 && potionPosition.getY() != 0) { // TODO

    for (size_t j = 0; j < fellows.size(); ++j){
      fellows[j]->targetPosition = Position(potionPosition.getX(), potionPosition.getY());
    }
  } else {
    for (size_t j = 0; j < fellows.size(); ++j){
      fellows[j]->targetPosition = Position(targetPosition.getX(), targetPosition.getY());
    }
  }
}
  // add monsters to map
  for (size_t i = 0; i < monsters.size(); ++i){
    map[monsters[i]->position.getX()][monsters[i]->position.getY()] = monsters[i]->symbole;
  }


}

void Grid::moveMonsters() {
  for(size_t i = 0; i < monsters.size(); ++i){
    std::vector<bool> availableMovesV = availableMoves(*monsters[i]);
    monsters[i]->move(availableMovesV);
  }
}

void Grid::moveFellows(){
  for(size_t i = 0; i < fellows.size(); ++i){
    std::vector<bool> availableMovesV;
    availableMovesV = availableMoves(*fellows[i]);
    fellows[i]->move(availableMovesV);
  }
}
