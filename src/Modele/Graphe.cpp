#include "../../lib/Modele/Graphe.hpp"
Graphe::Graphe() : points(), aretes() {}

Graphe::~Graphe() {
    for (Point* p : points) delete p;
}

Point* Graphe::ajouterPoint(Point* p) {
    points.push_back(p);
    return p;
}

const std::vector<Point*>& Graphe::getPoints() const {
    return points;
}

const std::vector<Arete>& Graphe::getAretes() const {
    return aretes;
}

void Graphe::relier(Point* a, Point* b) {
    aretes.emplace_back(a, b);
}

void Graphe::appliquerForce(const Vecteur& force){
    for (Point* p : points) {
        p->appliquerForce(force);
    }
}

void Graphe::actualiser(float width, float height){
    for (int i = 0; i < 10; ++i) {
        for (Arete& a : aretes) {
            a.appliquerContrainte();
        }
    }

    for (Point* p : points) {
        p->actualiser(width, height);
    }
}