#include "main.hh"

int main() {
  std::string data[] = {
    #include "data.txt"
  };

  auto grid = std::make_unique<Grid>(data);

  //while (true) {
  for (int i = 0; i < 5; ++i) {

    auto target = std::make_unique<Target>(Position(1, 2));
    std::cout << "plop " << target->symbole << std::endl;
    //system("clear");
    //std::cout << "Round " << i + 1 << std::endl;
    if (grid->monstersWin()) {
      std::cout << "Monsters wins" << std::endl;
      return 0;
    }

    moveFellow(grid);

    if (grid->fellow->win()) {
      std::cout << "Fellow wins" << std::endl;
      return 1;
    }

    //moveMonsters(grid);

    grid->displayMap();
    //std::cin.ignore();
  }
}

void moveFellow(std::unique_ptr<Grid> const &grid) {
  std::vector<bool> availableMovesV;
  if (grid->hasPotion){
    availableMovesV = grid->availableMoves(*grid->fellow, '*');
  } else {
    availableMovesV = grid->availableMoves(*grid->fellow, 'T');
  }

  grid->fellow->move(availableMovesV);

  grid->update();
}

void moveMonsters(std::unique_ptr<Grid> const &grid) {
  grid->moveMonsters();
  //grid->update();
}
