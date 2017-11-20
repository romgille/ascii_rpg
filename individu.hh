#include "objet_mobile.hh"

class Individu : public ObjetMobile
{
    public:
        Individu() {
            this->symbole = 'i';
            this->deplacement = 1;
            this->position = new Position(0, 0);
        }
};
