#ifndef GRID_HH
#define GRID_HH

#include <string>
#include <memory>
#include <vector>
#include <iostream>

#include "Monster.hh"
#include "ImmobileObject.hh"
#include "Fellow.hh"
#include "Target.hh"
#include "DumbMonster.hh"
#include "Rock.hh"
#include "Potion.hh"
#include "NotSoDumbMonster.hh"
#include "Money.hh"
#include "MovableObject.hh"

class Grid {
public:
  std::vector<std::unique_ptr<Monster>> monsters;
  std::vector<std::unique_ptr<ImmobileObject>> immobileObjects;
  std::vector<std::unique_ptr<Fellow>> fellows;
  std::vector<std::vector<char>> map;

  size_t size = 8;
  bool hasPotion = false;
  bool hasMoney = false;

  Grid(std::string data[]);
  ~Grid() = default;

  bool monstersWin();

  void displayMap();

  void moveMonsters();

  void moveFellows();

  bool fellowsWin();

  std::vector<bool> availableMoves(MovableObject& movable);

  void update();
};

#endif
