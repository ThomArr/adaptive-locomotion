#include "../../lib/Modele/SystemePhysique.hpp"

void SystemePhysique::ajouterGraphe(Graphe & p) {
    graphes.push_back(p);
}

void SystemePhysique::miseAJour(float width, float height) {
    for (size_t i = 0; i < graphes.size(); ++i){
        graphes[i].appliquerForce(gravite);
        graphes[i].actualiser(width, height);
    }
}

const std::vector<Graphe>& SystemePhysique::getGraphes() const {
    return graphes;
}