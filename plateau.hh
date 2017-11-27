#ifndef PLATEAU_H
#define PLATEAU_H
#include "objet.hh"
#include <string>

class Plateau {
private:
    unsigned int size;
    Objet **tableau;

    void createTableau();

public:
    // Plateau without data.txt
    Plateau(int size = 8);

    // Plateau with data.txt
    Plateau(std::string filepath);

    ~Plateau();

    int getLengthFile(std::string filepath);

    void draw();
};

#endif