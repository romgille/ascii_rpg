#include "objet.hh"

class ObjetMobile : public Objet
{
    protected:
        int deplacement;

    public:
        void move(int x, int y) {
            this->position->move(x, y);
        }

};
