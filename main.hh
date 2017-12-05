#include <iostream>
#include <string>
#include <memory>

#include "Grid.hh"

void moveFellow(std::unique_ptr<Grid> const &grid);
void moveMonsters(std::unique_ptr<Grid> const &grid);
int main();
