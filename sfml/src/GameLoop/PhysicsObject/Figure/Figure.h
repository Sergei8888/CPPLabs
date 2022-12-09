//
// Created by Sergei Kuzmenkov on 05.12.2022.
//
#include <SFML/Graphics.hpp>
#include "../PhysicsObject.h"

#ifndef HARDEND_FIGURE_H
#define HARDEND_FIGURE_H

class Figure : public PhysicsObject {
private:
    // Get shape width and height sfml
    sf::Vector2f getSize() const {
        return {shape->getGlobalBounds().width, shape->getGlobalBounds().height};
    }

public:
    // SFML base drawable shape object
    sf::Shape *shape;

    explicit Figure(sf::Shape *shape) {
        this->shape = shape;
    }

    // Must be called on every game loop iteration
    void updatePosition() {
        this->shape->move(this->velocity);
    };

    /**
     * Fixes screen collisions of the shape
     * @param window
     */
    void fixScreenCollision(sf::Vector2<unsigned int> windowSize) {
        // Left side
        if (this->shape->getPosition().x - getSize().x / 2 < 0) {
            this->stopMotion();
            this->shape->setPosition(getSize().x / 2, this->shape->getPosition().y);
        }

        // Top side
        if (this->shape->getPosition().y - getSize().y / 2 < 0) {
            this->stopMotion();
            this->shape->setPosition(this->shape->getPosition().x, getSize().y / 2);
        }

        // Right side
        if (this->shape->getPosition().x + getSize().x / 2 > windowSize.x) {
            this->stopMotion();
            this->shape->setPosition(windowSize.x - getSize().x / 2, this->shape->getPosition().y);
        }

        // Bottom side
        if (this->shape->getPosition().y + getSize().y / 2 > windowSize.y) {
            this->stopMotion();
            this->shape->setPosition(this->shape->getPosition().x, windowSize.y - getSize().y / 2);
        }
    }
};

#endif //HARDEND_FIGURE_H
