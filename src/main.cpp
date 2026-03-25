#include <SFML/Graphics.hpp>
#include <iostream>
#include "../lib/Modele/SystemePhysique.hpp"
#include "../lib/Vue/VueSFML.hpp"
#include "../lib/Controleur/Controleur.hpp"

int main() {
    unsigned width = 800u;
    unsigned height = 600u;
    sf::RenderWindow window(sf::VideoMode({width, height}), "Points et Vecteurs avec SFML");
    SystemePhysique systeme;
    VueSFML vue(window, systeme);
    Controleur controleur(window, systeme, vue);

    Graphe g = Graphe();
    
    Point p1 = Point(400.f, 150.f, true);
    g.ajouterPoint(&p1);

    Point p2 = Point(450.f, 150.f, false);
    g.ajouterPoint(&p2);

    Point p3 = Point(500.f, 150.f, false);
    g.ajouterPoint(&p3);

    Point p4 = Point(550.f, 150.f, false);
    g.ajouterPoint(&p4);

    Point p5 = Point(525.f, 185.f, false);
    g.ajouterPoint(&p5);

    g.relier(&p1,&p2);
    g.relier(&p2,&p3);
    g.relier(&p3,&p4);
    g.relier(&p3,&p5);
    g.relier(&p5,&p4);


    systeme.ajouterGraphe(g);

    while (window.isOpen()) {
        controleur.gererEvenements();
        systeme.miseAJour(width, height-10);
        vue.dessiner();
    }

    return 0;
}