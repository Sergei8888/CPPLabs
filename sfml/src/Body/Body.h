//
// Created by Sergei Kuzmenkov on 28.11.2022.
//

#ifndef HARDEND_BODY_H
#define HARDEND_BODY_H


class Body {
public:
    virtual void updatePosition() = 0;

    void stopMotion() {
        this->velocity = sf::Vector2<float>(0, 0);
        this->acceleration = sf::Vector2<float>(0, 0);
    }

    sf::Vector2<float> velocity;
    sf::Vector2<float> acceleration;
};


#endif //HARDEND_BODY_H
