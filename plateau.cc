#include "plateau.hh"
#include <iostream>

void Plateau::createTableau() {
    this->tableau = new Objet *[size];
    for (unsigned int i = 0; i < size; ++i) {
        this->tableau[i] = new Objet[size];
    }
}

Plateau::Plateau(int size) {
    this->size = size;
    createTableau();
}

//Plateau::Plateau(std::string filepath) {
//    this->size = getLengthFile(filepath);
//    createTableau();
//
//    unsigned int i = 0;
//    unsigned int j = 0;
//    char ch;
//    std::fstream fin(filepath, std::fstream::in);
//    while (fin >> std::noskipws >> ch) {
//
//    }
//}
//
//int Plateau::getLengthFile(std::string filepath) {
//    std::ifstream file(filepath);
//    std::string str;
//    std::getline(file, str);
//    return str.length();
//}

void Plateau::draw() {
    std::string str = "";
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            str += tableau[i][j].symbole;
        }
        str += "\n";
    }
    std::cout << str << std::endl;
}
