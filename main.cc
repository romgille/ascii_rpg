#include <string>
#include <iostream>
#include <random>
#include <fstream>

#include "direction.hh"
#include "plateau.hh"
#include "individu.hh"

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

    for (size_t i = 0; i < plateau->objets.size(); ++i){
      if(!plateau->objets[i]){
        continue;
      }

      if (plateau->objets[i]->symbole == 'i'){
        auto ptr = static_cast<Individu*>(plateau->objets[i].get());
        ptr->move();
      }
    }

    plateau->print();


//    std::cout << plateau->getSize() << std::endl;

//    std::cout << "size: " << plateau->getLengthFile("data.txt") << std::endl;
}
