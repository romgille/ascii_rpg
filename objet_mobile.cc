#include "objet_mobile.hh"
#include <experimental/random>

void ObjetMobile::move() {
  this->position.move(
    std::experimental::randint(0, ObjetMobile::deplacement),
    std::experimental::randint(0, ObjetMobile::deplacement)
  );
}
