#ifndef CONTROLLEUR_HPP
#define CONTROLLEUR_HPP

#include <SFML/Window/Event.hpp>
#include "../Modele/SystemePhysique.hpp"
#include "../Vue/VueSFML.hpp"

class Controleur {
private:
    sf::RenderWindow& window;
    SystemePhysique& systeme;
    VueSFML& vue;

public:
    Controleur(sf::RenderWindow& w, SystemePhysique& s, VueSFML& v);
    void gererEvenements();
};

#endif