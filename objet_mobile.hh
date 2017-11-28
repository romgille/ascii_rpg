#ifndef OBJET_MOBILE_H
#define OBJET_MOBILE_H
#include "objet.hh"

class ObjetMobile : public Objet {
protected:
    int deplacement;

public:
    void move(int x, int y);

};

#endif
