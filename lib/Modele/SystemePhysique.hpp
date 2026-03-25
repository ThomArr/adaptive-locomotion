#ifndef SYSTEMEPHYSIQUE_HPP
#define SYSTEMEPHYSIQUE_HPP

#include <vector>
#include "Point.hpp"
#include "Graphe.hpp"
#include "Vecteur.hpp"

class SystemePhysique
{
private:
    const Vecteur gravite = Vecteur{0, 0.005f};
    std::vector<Graphe> graphes;

public:
    void ajouterGraphe(Graphe &);

    void miseAJour(float width, float height);

    const std::vector<Graphe> &getGraphes() const;
};

#endif