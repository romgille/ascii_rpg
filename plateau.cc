#include "plateau.hh"
#include "individu.hh"
#include "monstre_con.hh"
#include "objectif.hh"
#include "rocher.hh"
#include "potion.hh"
#include "monstre_pas_con.hh"
#include "thune.hh"
#include <iostream>
#include <fstream>
#include <memory>

//void Plateau::createTableau() {
//    this->tableau = new Objet *[size];
//    for (unsigned int i = 0; i < size; ++i) {
//        this->tableau[i] = new Objet[size];
//    }
//}

Plateau::Plateau(std::string data[]){
  size_t size = data->size();
  for (size_t i = 0; i < size; ++i){
    for (size_t  j = 0; j < size; ++j){
      switch (data[i][j]) {
        case 'i':
        this->objets.push_back(std::make_unique<Individu>());
        break;
        case 'T':
        this->objets.push_back(std::make_unique<Objectif>());
        break;
        case 'm':
        this->objets.push_back(std::make_unique<MonstreCon>());
        break;
        case 'o':
        this->objets.push_back(std::make_unique<Rocher>());
        break;
        case '*':
        this->objets.push_back(std::make_unique<Potion>());
        break;
        case 'M':
        this->objets.push_back(std::make_unique<MonstrePasCon>());
        break;
        case '$':
        this->objets.push_back(std::make_unique<Thune>());
        break;
        default:
        this->objets.push_back(nullptr);
      }
    }
  }
  this->size = size;
}

void Plateau::print(){
  for (size_t i = 0; i < objets.size(); ++i){
    if (objets[i]){
      objets[i]->print();
    } else {
      std::cout << "null" << std::endl;
    }
  }
}

  Plateau::Plateau(int size) {
    this->size = size;
    //    createTableau();
  }

  unsigned int Plateau::getSize() {
    return this->size;
  }

  //Plateau::Plateau(std::string filepath) {
  //  this->size = getLengthFile(filepath);
  //  createTableau();
  //
  //  unsigned int i = 0;
  //  unsigned int j = 0;
  //  char ch;
  //  std::fstream fin(filepath, std::fstream::in);
  //  while (fin >> std::noskipws >> ch) {
  //
  //  }
  //}

  int Plateau::getLengthFile(std::string filepath) {
    std::ifstream file(filepath);
    std::string str;
    std::getline(file, str);
    return str.length();
  }

  //void Plateau::draw() {
  //    std::string str = "";
  //    for (int i = 0; i < this->size; ++i) {
  //        for (int j = 0; j < this->size; ++j) {
  //            str += tableau[i][j].symbole;
  //        }
  //        str += "\n";
  //    }
  //    std::cout << str << std::endl;
  //}
