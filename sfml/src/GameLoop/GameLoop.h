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
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void fillScene() {
        CircleBody *circle = new CircleBody(50, windowManager->getCenter(),
                                            sf::Color::Red);
        circle->velocity += sf::Vector2f(10, 10);
        scene->push_back(circle);
    }

    void startIteration() {
        windowManager->window->clear(sf::Color(150, 150, 150));

        for (auto *ball: *scene) {
            ball->updatePosition();
            windowManager->window->draw(*ball);
        }

        windowManager->window->display();
    }

    explicit GameLoop(WindowManager *windowManager) {
        this->windowManager = windowManager;
        fillScene();
    }
};


#endif //HARDEND_GAMELOOP_H
