#ifndef VIEWSFML_HPP
#define VIEWSFML_HPP

#include <SFML/Graphics.hpp>
#include "../Modele/SystemePhysique.hpp"

class VueSFML
{
private:
    sf::RenderWindow &window;
    SystemePhysique &systeme;

public:
    VueSFML(sf::RenderWindow &w, SystemePhysique &s);

    void dessiner();
};

#endif