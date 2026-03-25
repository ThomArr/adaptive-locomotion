#ifndef ARETE_HPP
#define ARETE_HPP

#include "Point.hpp"

class Arete {
public:
    Point* a;
    Point* b;
    float longueur;

    Arete(Point* , Point* );

    void appliquerContrainte();

    void appliquerContrainteVitesse();
};

#endif