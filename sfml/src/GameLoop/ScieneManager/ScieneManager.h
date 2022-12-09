//
// Created by Sergei Kuzmenkov on 09.12.2022.
//
#include "SFML/Graphics.hpp"

#ifndef KURAMOTOMODEL_SCIENEMANAGER_H
#define KURAMOTOMODEL_SCIENEMANAGER_H

class ScieneManager {
public:
    static sf::CircleShape *createCircle() {
        const int radius = 50;
        auto *circle = new sf::CircleShape(radius);
        circle->setFillColor(sf::Color::Red);
        circle->setOrigin(radius, radius);
        return circle;
    }
};

#endif //KURAMOTOMODEL_SCIENEMANAGER_H
