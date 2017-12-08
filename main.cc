#include "main.hh"

int main() {
  std::string data[] = {
    #include "data.txt"
  };

  auto grid = std::make_unique<Grid>(data);

  int round = 0;
  while (true) {
    system("clear");
    std::cout << "Round " << round + 1 << std::endl;

    moveFellow(grid);

    if (grid->fellowsWin()) {
      std::cout << "Fellow wins on round " << round + 1 << std::endl;
      grid->displayMap();
      return 1;
    }

    moveMonsters(grid);

    if (grid->monstersWin()) {
      std::cout << "Monsters wins on round " << round + 1 << std::endl;
      grid->displayMap();
      return 0;
    }

    grid->displayMap();
    std::cin.ignore();
    ++round;
  }
}

void moveFellow(std::unique_ptr<Grid> const &grid) {
  grid->moveFellows();
  grid->update();
}

void moveMonsters(std::unique_ptr<Grid> const &grid) {
  grid->moveMonsters();
  grid->update();
}
