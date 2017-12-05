#include "main.hh"

int main() {
  std::string data[] = {
    #include "data.txt"
  };

  auto grid = std::make_unique<Grid>(data);

  while (true) {

    if (grid->monstersWin()) {
      std::cout << "Monsters wins" << std::endl;
      return 0;
    }

    moveFellow(grid);

    //if (grid->fellow->win()) {
    //  std::cout << "Fellow wins" << std::endl;
    //  return 1;
    //}
//
    //moveMonsters(grid);
//
    //grid->displayMap();

  }
}

void moveFellow(std::unique_ptr<Grid> const &grid) {
  //auto fellow = static_cast<std::unique_ptr<MovableObject>>(grid->fellow.release());

  if (grid->hasPotion){
    auto availableMovesV = grid->availableMoves(*grid->fellow, '*');
  }

  auto availableMovesV = grid->availableMoves(*grid->fellow, 'T');
  //grid->fellow->move(availableMovesV);
//
  //grid->update();
}

void moveMonsters(std::unique_ptr<Grid> const &grid) {
  grid->moveMonsters();
  grid->update();
}
