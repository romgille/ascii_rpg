#include "main.hh"

int main() {

  system("clear");
  std::cout << "                         _  __ ________  _  _  __" << '\n';
  std::cout << "| | _ | _ _ __  _  o__  |_|(_ /   |  |  |_)|_)/__" << '\n';
  std::cout << "|^|(/_|(_(_)|||(/_ || | | |__)\\___|__|_ | \\|  \\_|" << '\n';

  std::cout << "Press ENTER to go next" << std::endl;

  std::cin.ignore();

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
    std::cout << "Press ENTER to go next" << std::endl;
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
