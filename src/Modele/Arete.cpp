#include "../../lib/Modele/Arete.hpp"

Arete::Arete(Point* alpha, Point* beta)
    : a(alpha), b(beta), longueur(0) {
    Vecteur diff = b->position - a->position;
    longueur = diff.norme();
}

void Arete::appliquerContrainte() {
    Vecteur diff = b->position - a->position;
    float dist = diff.norme();
    if (dist == 0.f) return; // éviter division par zéro

    // vecteur unitaire le long de l'arête
    Vecteur dir = diff / dist;

    // vitesse relative projetée sur la direction de l'arête
    float vRel = (b->vitesse - a->vitesse).dot(dir);

    // écart par rapport à la longueur désirée
    float delta = dist - longueur;

    // appliquer une correction pour réduire vRel
    Vecteur correction = ((vRel + delta) / 2.f) * dir;

    a->vitesse += correction;
    b->vitesse -= correction;
}