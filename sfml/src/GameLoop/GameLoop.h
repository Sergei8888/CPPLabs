//
// Created by Sergei Kuzmenkov on 28.11.2022.
//
#include <chrono>
#include "../WindowManager/WindowManager.h"

#ifndef HARDEND_GAMELOOP_H
#define HARDEND_GAMELOOP_H


class GameLoop {
private:
    WindowManager *windowManager;
public:
    std::vector<CircleBody *> *scene = new std::vector<CircleBody *>;

    void main() {
        while (true) {
            this->startIteration();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void fillScene() {
        CircleBody *circle1 = new CircleBody(50, windowManager->getCenter(),
                                             sf::Color::Red);
        circle1->velocity += sf::Vector2f(0, 2);
        scene->push_back(circle1);

        CircleBody *circle2 = new CircleBody(50, windowManager->getCenter(),
                                             sf::Color::Red);
        circle2->velocity += sf::Vector2f(2, 0);
        scene->push_back(circle2);

        CircleBody *circle3 = new CircleBody(50, windowManager->getCenter(),
                                             sf::Color::Red);
        circle3->velocity += sf::Vector2f(-2, 0);
        scene->push_back(circle3);

        CircleBody *circle4 = new CircleBody(50, windowManager->getCenter(),
                                             sf::Color::Red);
        circle4->velocity += sf::Vector2f(0, -2);
        scene->push_back(circle4);
    }

    void startIteration() {
        windowManager->window->clear(sf::Color(150, 150, 150));

        for (auto *ball: *scene) {
            ball->updatePosition();
        }

        fixCollisions();

        for (auto *ball: *scene) {
            windowManager->window->draw(*ball);
        }

        windowManager->window->display();
    }


    void fixCollisions() {
        for (auto *ball: *scene) {
            ball->fixScreenCollision(windowManager->window->getSize());
//            for (auto *ball2: *scene) {
//                if (ball == ball2) {
//                    continue;
//                }
//                if (ball->isColliding(ball2)) {
//                    ball->resolveCollision(ball2);
//                }
//            }
        }
    }

    explicit GameLoop(WindowManager *windowManager) {
        this->windowManager = windowManager;
        fillScene();
    }
};


#endif //HARDEND_GAMELOOP_H
