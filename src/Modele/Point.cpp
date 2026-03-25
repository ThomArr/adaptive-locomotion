#include "../../lib/Modele/Point.hpp"
#include <stdlib.h>

Point::Point(float x, float y, bool f) : position{Vecteur{x,y}}, fixe{f}, vitesse{0,0}, acceleration{0,0} {}

float Point::getX() const{
    return position.dx;
}
float Point::getY() const{
    return position.dy;
}

float Point::getDX() const {
    return vitesse.dx;
}

float Point::getDY() const {
    return vitesse.dy;
}

void Point::setFixe(bool b){
    fixe = b;
}

void Point::appliquerForce(const Vecteur& force) {
    if (fixe){
        vitesse = Vecteur(0,0);
        acceleration = Vecteur(0,0);
        return;
    }
    acceleration += force;
}

void Point::actualiser(float width, float height){
    if (fixe){
        vitesse = Vecteur(0,0);
        acceleration = Vecteur(0,0);
        return;
    }

    vitesse += acceleration;
    position += vitesse;
    acceleration = Vecteur(0,0);

    bool changement = true;
    while (changement){
        changement = false;
        if (position.dx < 0) {
            position.dx *= -1;
            vitesse.dx = 0.8*abs(vitesse.dx);
            vitesse.dy *= 0.8;
            changement = true;
        }
        if (position.dx > width) {
            position.dx -= (position.dx-width)*2;
            vitesse.dx = -0.8*abs(vitesse.dx);
            vitesse.dy *= 0.8;
            changement = true;
        }

        if (position.dy < 0) {
            position.dy *= -1;
            vitesse.dy = 0.8*abs(vitesse.dy);
            vitesse.dx *= 0.8;
            changement = true;
        }
        if (position.dy > height) {
            position.dy -= (position.dy-height)*2;
            vitesse.dy = -0.8*abs(vitesse.dy);
            vitesse.dx *= 0.8;
            changement = true;
        }
    }
}