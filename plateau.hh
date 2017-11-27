#ifndef PLATEAU_H
#define PLATEAU_H
#include "objet.hh"
#include <string>
#include <vector>
#include <memory>

class Plateau {
private:
  unsigned int size;
  std::vector<std::unique_ptr<Objet>> objets;

  void createTableau();

public:
  // Plateau without data.txt
  Plateau(int size = 8);

  Plateau(std::string data[]);

  std::string print();
  // Plateau with data.txt
//  Plateau(std::string filepath);

  ~Plateau();

  int getLengthFile(std::string filepath);

  void draw();

  unsigned int getSize();
};

#endif
