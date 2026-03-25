#ifndef POINT_HPP
#define POINT_HPP

#include "Vecteur.hpp"

class Point
{
private:
    Vecteur position;
    bool fixe;
    Vecteur vitesse;
    Vecteur acceleration;

public:
    Point(float x, float y, bool f);

    Vecteur getPosition() const;
    float getX() const;
    float getY() const;
    float getDX() const;
    float getDY() const;

    void setFixe(bool);
    void appliquerForce(const Vecteur& force);
    void actualiser(float width, float height);

    friend class Arete;
};

#endif