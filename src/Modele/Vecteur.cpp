#include "../../lib/Modele/Vecteur.hpp"

#include <math.h>

Vecteur::Vecteur(float dx, float dy) : dx(dx), dy(dy) {}

float Vecteur::norme(){
    return sqrt(dx*dx+dy*dy);
}

Vecteur Vecteur::normalise(){
    return norme() * *this;
}

float Vecteur::dot(const Vecteur& autre){
    return dx*autre.dx + dy*autre.dy;
}

Vecteur& Vecteur::operator+=(const Vecteur& autre) {
    dx += autre.dx;
    dy += autre.dy;
    return *this;
}

Vecteur& Vecteur::operator-=(const Vecteur& autre) {
    dx -= autre.dx;
    dy -= autre.dy;
    return *this;
}

Vecteur operator+(Vecteur gauche, const Vecteur& droite) {
    gauche += droite;
    return gauche;
}

Vecteur operator-(Vecteur gauche, const Vecteur& droite) {
    gauche -= droite;
    return gauche;
}

Vecteur operator*(float coeff, const Vecteur& vecteur) {
    return Vecteur(vecteur.dx * coeff, vecteur.dy * coeff);
}


Vecteur operator/(const Vecteur& vecteur, float coeff) {
    return Vecteur(vecteur.dx / coeff, vecteur.dy / coeff);
}