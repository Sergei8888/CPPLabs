//
// Created by Sergei Kuzmenkov on 28.11.2022.
//
#include <SFML/Graphics.hpp>

#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

class PhysicsObject {
public:
    sf::Vector2<float> velocity;
    sf::Vector2<float> acceleration;

    void stopMotion() {
        this->velocity = sf::Vector2<float>(0, 0);
        this->acceleration = sf::Vector2<float>(0, 0);
    }
};

#endif // PHYSICS_OBJECT_H
