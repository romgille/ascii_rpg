#include "objet_mobile.hh"
#include <experimental/random>

void ObjetMobile::move() {
  int x = std::experimental::randint(0, ObjetMobile::deplacement);
  int y = x == 0 ? ObjetMobile::deplacement : 0;
  this->position.move(x, y);
}
