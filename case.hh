#include "objet.hh"

class Case
{
    private:
        Position *position;
        Objet *content;

    public:
        Position getPosition() { return *this->position; }

        void setPosition(Position *position) {
            *this->position = *position;
        }

        Objet getContent() { return *this->content; }

        void setContent(Objet *content) { *this->content = *content; }
};
