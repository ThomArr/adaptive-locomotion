#include "../../lib/Controleur/Controleur.hpp"

Controleur::Controleur(sf::RenderWindow& w, SystemePhysique& s, VueSFML& v)
    : window(w), systeme(s), vue(v) {}

void Controleur::gererEvenements() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}