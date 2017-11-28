#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <map>

#include "direction.hh"
#include "plateau.hh"
#include "individu.hh"
#include "monstre_con.hh"

int main() {
    //std::random_device rd;
    //std::mt19937 mt(rd());
    //std::uniform_int_distribution<int> distribution(0, 3);

    std::string data[] = {
#include "data.txt"
    };
    //for (auto s : data) std::cout << s << std::endl;

    //Directions test = Directions(distribution(mt));
    //std::cout << "direction: " << test << std::endl;

    Plateau *plateau = new Plateau(data);
    plateau->print();

    typedef std::map<char, Position> SymbPosMap;
    typedef std::pair<char, Position> SymbPosPair;

    SymbPosMap positions;

    for (size_t i = 0; i < plateau->objets.size(); ++i){
      if (plateau->objets[i]) {
        positions.insert(
          SymbPosPair(
            plateau->objets[i]->symbole,
            Position(plateau->objets[i]->position.x, plateau->objets[i]->position.y)
          )
        );
      }
    }

    for (size_t i = 0; i < plateau->objets.size(); ++i){
      if(!plateau->objets[i]){
        continue;
      }

      if (plateau->objets[i]->symbole == 'i'){
        auto ptr = static_cast<Individu*>(plateau->objets[i].get());
        ptr->move(positions['T']);
      }
      if (plateau->objets[i]->symbole == 'm'){
        auto ptr = static_cast<MonstreCon*>(plateau->objets[i].get());
        ptr->move(positions['i']);
      }
    }

    plateau->print();


//    std::cout << plateau->getSize() << std::endl;

//    std::cout << "size: " << plateau->getLengthFile("data.txt") << std::endl;
}
