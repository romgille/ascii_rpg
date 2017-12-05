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
  std::unique_ptr<Fellow> fellow;
  std::vector<std::vector<char>> map;

  bool hasPotion = false;
  bool hasMoney = false;

  Grid(std::string data[]);
  ~Grid() = default;

  bool monstersWin();

  void displayMap();

  void moveMonsters();

  template<class T>
  std::vector<bool> availableMoves(T& movable, char target);

  void update();
};

#endif
