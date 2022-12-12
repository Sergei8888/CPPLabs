//
// Created by Sergei Kuzmenkov on 09.12.2022.
//
#include "../PhysicsObject/Figure/Figure.h"
#include "SFML/Graphics.hpp"

#ifndef KURAMOTOMODEL_SCIENEMANAGER_H
#define KURAMOTOMODEL_SCIENEMANAGER_H

class ScieneManager {
public:
    static Figure *createCircleFigure() {
        const int RADIUS = 50;

        auto circleShape = new sf::CircleShape(RADIUS);
        circleShape->setPosition(100, 100);
        circleShape->setFillColor(sf::Color::Red);
        circleShape->setOrigin(RADIUS, RADIUS);

        auto circle = new Figure(circleShape);
        circle->velocity = sf::Vector2f(0, 5);

        return circle;
    }

    static Figure *createRectangleFigure() {
        const int WIDTH = 100;
        const int HEIGHT = 100;

        auto rectangleShape = new sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
        rectangleShape->setPosition(200, 200);
        rectangleShape->setFillColor(sf::Color::Green);
        rectangleShape->setOrigin(WIDTH / 2, HEIGHT / 2);

        auto rectangle = new Figure(rectangleShape);
        rectangle->velocity = sf::Vector2f(5, 0);

        return rectangle;
    }
};

#endif //KURAMOTOMODEL_SCIENEMANAGER_H
