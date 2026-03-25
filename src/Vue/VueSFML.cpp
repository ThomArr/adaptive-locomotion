#include "../../lib/Vue/VueSFML.hpp"

#include <iostream>

VueSFML::VueSFML(sf::RenderWindow& w, SystemePhysique& s) : window(w), systeme(s) {}

void VueSFML::dessiner() {
    window.clear(sf::Color::Black);

    for (size_t i = 0; i < systeme.getGraphes().size(); ++i) {
        for (size_t j = 0; j < systeme.getGraphes()[i].getPoints().size(); ++j){
            const Point* p = systeme.getGraphes()[i].getPoints()[j];
            sf::CircleShape pointShape(5.f);
            pointShape.setPosition(sf::Vector2f(p->getX(), p->getY()));
            pointShape.setFillColor(sf::Color::Red);
            window.draw(pointShape);

            sf::Vertex ligne[2];

            ligne[0].position = sf::Vector2f(p->getX() + 5, p->getY() + 5);
            ligne[0].color = sf::Color::Green;

            ligne[1].position = sf::Vector2f(p->getX() + 5 + p->getDX()*100, p->getY() + 5 + p->getDY()*100);
            ligne[1].color = sf::Color::Green;

            window.draw(ligne, 2, sf::PrimitiveType::Lines);
        }
        for (size_t j = 0; j < systeme.getGraphes()[i].getAretes().size(); ++j){
            const Arete a = systeme.getGraphes()[i].getAretes()[j];
            
            sf::Vertex ligne[2];

            ligne[0].position = sf::Vector2f(a.a->getX() + 5, a.a->getY() + 5);
            ligne[0].color = sf::Color::White;

            ligne[1].position = sf::Vector2f(a.b->getX() + 5, a.b->getY() + 5);
            ligne[1].color = sf::Color::White;

            window.draw(ligne, 2, sf::PrimitiveType::Lines);
        }
    }

    window.display();
}