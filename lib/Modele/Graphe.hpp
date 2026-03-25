#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include <vector>
#include <iostream>
#include "Vecteur.hpp"
#include "Arete.hpp"

class Graphe {
public:
    std::vector<Point*> points;
    std::vector<Arete> aretes;

    Graphe();
    ~Graphe();

    Point* ajouterPoint(Point* p);

    const std::vector<Point *>& getPoints() const;
    const std::vector<Arete>& getAretes() const;

    void relier(Point* a, Point* b);

    void appliquerForce(const Vecteur& force);
    void actualiser(float width, float height);
};

#endif