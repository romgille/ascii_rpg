#include "objet_mobile.hh"
#include <experimental/random>

void ObjetMobile::move(Position target) {
  if (target.y < this->position.y) {
    this->position.move(0, -this->deplacement);
  } else if (target.y > this->position.y) {
    this->position.move(0, this->deplacement);
  } else if (target.x < this->position.x){
    this->position.move(-this->deplacement, 0);
  } else if (target.x > this->position.x) {
    this->position.move(this->deplacement, 0);
  }
}
