#ifndef OBJET_H
#define OBJET_H
#include "position.hh"

class Objet {
public:
    char symbole;
    Position position;
    void print();
};

#endif
