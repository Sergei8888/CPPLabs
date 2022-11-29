//
// Created by Sergei Kuzmenkov on 27.11.2022.
//

#include <iostream>
#include "../Body.h"

#ifndef HARDEND_BALL_H
#define HARDEND_BALL_H


class CircleBody : public sf::CircleShape, public Body {
public:
    void updatePosition() override {
        this->setPosition(this->getPosition() + this->velocity);
    }

    explicit CircleBody(int radius = 0, sf::Vector2<float> position = sf::Vector2<float>(0, 0),
                        sf::Color color = sf::Color::White)
            : sf::CircleShape(radius) {
        this->setOrigin(radius / 2, radius / 2);
        this->setFillColor(color);
        this->setPosition(position);
    }
};


#endif //HARDEND_BALL_H
