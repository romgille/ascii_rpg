#include "objet_mobile.hh"
#include <experimental/random>

void ObjetMobile::move(int x, int y) {
  this->position.move(x, y);
}
