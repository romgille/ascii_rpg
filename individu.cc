#include "individu.hh"

Individu::Individu() {
  this->symbole = 'i';
  this->deplacement = 1;
  this->position = Position();
}

Individu::Individu(Position p) {
  this->symbole = 'i';
  this->deplacement = 1;
  this->position = p;
}

//void Individu::move(Position target){
//  if (target.y < this->position.y) {
//    ObjetMobile::move(0, -this->deplacement);
//  } else if (target.y > this->position.y) {
//    ObjetMobile::move(0, this->deplacement);
//  }
//  if (target.x < this->position.x){
//    ObjetMobile::move(-this->deplacement, 0);
//  } else if (target.x > this->position.x) {
//    ObjetMobile::move(this->deplacement, 0);
//}
