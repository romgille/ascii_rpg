#include "Grid.hh"

Grid::Grid(std::string data[]) {
  map.resize(data->size());
  for (size_t i = 0; i < data->size(); ++i){
    map[i].resize(data->size());
    for (size_t j = 0; j < data->size(); ++j){
      switch (data[i][j]) {
        case 'i':
        fellow = std::make_unique<Fellow>(Position(i, j));
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
  for (size_t i = 0; i < monsters.size(); ++i) {
    if (!monsters[i]->win()){
      return false;
    }
  }
  return true;
}

void Grid::displayMap() {
  std::cout << "\"";
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      std::cout << map[i][j];
    }
    std::cout << "\"," << std::endl;
    std::cout << "\"";
  }
  std::cout << std::endl;
}

template<class T>
std::vector<bool> Grid::availableMoves(T& movable, char target) {
  bool north = true;
  bool south = true;
  bool east = true;
  bool west = true;
  bool northE = true;
  bool southE = true;
  bool southW = true;
  bool northW = true;

  //std::cout << map[movable.position.getX()][movable.position.getY()];
//  std::cout << movable.deplacement;
  std::cout << typeid(movable).name() << std::endl;
  // TODO faire avec std::find vector avec vector canWalk et cannotWalk
  //if (map[movable.position.getX() - movable.deplacement][movable.position.getY()] != ' ' ||
  //map[movable.position.getX() - movable.deplacement][movable.position.getY()] != target ||
  //map[movable.position.getX() - movable.deplacement][movable.position.getY()] != '$') {
  //  north = false;
  //}
  //if (map[movable.position.getX() + movable.deplacement][movable.position.getY()] != ' ' ||
  //map[movable.position.getX() + movable.deplacement][movable.position.getY()] != target ||
  //map[movable.position.getX() + movable.deplacement][movable.position.getY()] != '$') {
  //  south = false;
  //}
  //if (map[movable.position.getX()][movable.position.getY() - movable.deplacement] != ' ' ||
  //map[movable.position.getX()][movable.position.getY() - movable.deplacement] != target ||
  //map[movable.position.getX()][movable.position.getY() - movable.deplacement] != '$') {
  //  west = false;
  //}
  //if (map[movable.position.getX()][movable.position.getY() + movable.deplacement] != ' ' ||
  //map[movable.position.getX()][movable.position.getY() + movable.deplacement] != target ||
  //map[movable.position.getX()][movable.position.getY() + movable.deplacement] != '$') {
  //  east = false;
  //}
  //if (map[movable.position.getX() - movable.deplacement][movable.position.getY() - movable.deplacement] != ' ' ||
  //map[movable.position.getX() - movable.deplacement][movable.position.getY() - movable.deplacement] != target) {
  //  northW = false;
  //}
  //if (map[movable.position.getX() + movable.deplacement][movable.position.getY() - movable.deplacement] != ' ' ||
  //map[movable.position.getX() + movable.deplacement][movable.position.getY() - movable.deplacement] != target) {
  //  southW = false;
  //}
  //if (map[movable.position.getX() + movable.deplacement][movable.position.getY() + movable.deplacement] != ' ' ||
  //map[movable.position.getX() + movable.deplacement][movable.position.getY() + movable.deplacement] != target) {
  //  southE = false;
  //}
  //if (map[movable.position.getX() - movable.deplacement][movable.position.getY() + movable.deplacement] != ' ' ||
  //map[movable.position.getX() - movable.deplacement][movable.position.getY() + movable.deplacement] != target) {
  //  northE = false;
  //}
//
  std::vector<bool> availablesMoves = {north, south, east, west, northW, southW, southE, northE};
  return availablesMoves;
}

void Grid::update() {
  Position potionPosition;
  int potionIndex;
  Position moneyPosition;

  for(size_t i = 0; i < map.size(); ++i){
    for(size_t  j = 0; j < map.size(); ++j){
      map[i][j] = ' ';
    }
  }
  for (size_t i = 0; i < immobileObjects.size(); ++i){
    map[immobileObjects[i]->position.getX()][immobileObjects[i]->position.getY()] = immobileObjects[i]->symbole;
    if (immobileObjects[i]->symbole == '*') {
      potionPosition = Position(immobileObjects[i]->position.getX(), immobileObjects[i]->position.getY());
      potionIndex = i;
    }
    if (immobileObjects[i]->symbole == '$') {
      moneyPosition = Position(immobileObjects[i]->position.getX(), immobileObjects[i]->position.getY());
    }
  }
  for (size_t i = 0; i < monsters.size(); ++i){
    map[monsters[i]->position.getX()][monsters[i]->position.getY()] = monsters[i]->symbole;
  }
  map[fellow->position.getX()][fellow->position.getY()] = fellow->symbole;

  if (Position(fellow->position.getX(), fellow->position.getY()) == potionPosition) {
    fellow->deplacement = 2;
    immobileObjects.erase(immobileObjects.begin() + potionIndex);
    hasPotion = false;
  }
  if (Position(fellow->position.getX(), fellow->position.getY()) == moneyPosition) {
    fellow->winner = true;
  }
}

void Grid::moveMonsters() {
  for(size_t i = 0; i < monsters.size(); ++i){
    auto monster = static_cast<std::unique_ptr<MovableObject>>(monsters[i].get());
    std::vector<bool> availableMovesV = availableMoves(*monster, 'i');
    monsters[i]->move(availableMovesV);
  }
}
