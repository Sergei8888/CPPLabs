//
// Created by Sergei Kuzmenkov on 27.11.2022.
//
#include<cmath>
#include <iostream>
#include "../Body.h"

#ifndef HARDEND_BALL_H
#define HARDEND_BALL_H


class CircleBody : public sf::CircleShape, public Body {
public:
    void updatePosition() override {
        this->move(this->velocity);
    }

    void fixScreenCollision(sf::Vector2<unsigned int> windowSize) {
        // Left side
        if (this->getPosition().x - this->getRadius() < 0) {
            this->stopMotion();
            this->setPosition(this->getRadius(), this->getPosition().y);
        }

        // Top side
        if (this->getPosition().y - this->getRadius() < 0) {
            this->stopMotion();
            this->setPosition(this->getPosition().x, this->getRadius());
        }

        // Right side
        if (this->getPosition().x + this->getRadius() > windowSize.x) {
            this->stopMotion();
            this->setPosition(windowSize.x - this->getRadius(), this->getPosition().y);
        }

        // Bottom side
        if (this->getPosition().y + this->getRadius() > windowSize.y) {
            this->stopMotion();
            this->setPosition(this->getPosition().x, windowSize.y - this->getRadius());
        }
    }

    bool isPointInside(sf::Vector2<float> pointPosition) {
        const float xDiff = pointPosition.x - this->getPosition().x;
        const float yDiff = pointPosition.y - this->getPosition().y;
        // xDiff^2 + yDiff^2 <= radius^2
        return std::pow(xDiff, 2) + (std::pow(yDiff, 2)) <= std::pow(this->getRadius(), 2);
    }

    explicit CircleBody(int radius = 0, sf::Vector2<float> position = sf::Vector2<float>(0, 0),
                        sf::Color color = sf::Color::White)
            : sf::CircleShape(radius) {
        this->setOrigin(radius, radius);
        this->setFillColor(color);
        this->setPosition(position);
    }
};


#endif //HARDEND_BALL_H
