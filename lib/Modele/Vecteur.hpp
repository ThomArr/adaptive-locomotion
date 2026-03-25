#ifndef VECTEUR_HPP
#define VECTEUR_HPP

struct Vecteur
{
public:
    float dx, dy;
    
    Vecteur(float dx, float dy);

    float norme();
    Vecteur normalise();
    float dot(const Vecteur& autre);
    
    Vecteur& operator+=(const Vecteur& autre);
    Vecteur& operator-=(const Vecteur& autre);

    friend Vecteur operator+(Vecteur gauche, const Vecteur& droite);
    friend Vecteur operator-(Vecteur gauche, const Vecteur& droite);
    friend Vecteur operator*(float coeff, const Vecteur& vecteur);
    friend Vecteur operator/(const Vecteur& vecteur, float coeff);
};


#endif