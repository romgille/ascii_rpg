#include <string>
#include <iostream>
#include "individu.hh"

int main() {
  std::string data[] = {
    #include "data.txt"
  };
  for (auto s : data) std::cout << s << std::endl;

  //Individu *i = new Individu();
  //std::cout << "x : " << i->position->x << std::endl;
  //std::cout << "y : " << i->position->y << std::endl;

  //i->move(1, 2);
  //std::cout << "x : " << i->position->x << std::endl;
  //std::cout << "y : " << i->position->y << std::endl;
}
