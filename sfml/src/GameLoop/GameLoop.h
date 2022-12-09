//
// Created by Sergei Kuzmenkov on 28.11.2022.
//
#include "SFML/Graphics.hpp"
#include "ScieneManager/ScieneManager.h"
#include <chrono>
#include <stdnoreturn.h>
#include "PhysicsObject/Figure/Figure.h"
#include "../WindowManager/WindowManager.h"

#ifndef HARDEND_GAMELOOP_H
#define HARDEND_GAMELOOP_H


class GameLoop {
private:
    WindowManager *windowManager;
public:
    std::vector<Figure *> *scene = new std::vector<Figure *>;

    noreturn void main() {
        while (true) {
            this->runIteration();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void fillScene() const {
        auto circle = new Figure(ScieneManager::createCircle());
        scene->push_back(circle);
    }

    void runIteration() {
        windowManager->window->clear(sf::Color(150, 150, 150));

        for (auto *ball: *scene) {
            ball->updatePosition();
        }

        fixCollisions();

        for (auto *ball: *scene) {
            windowManager->window->draw(*ball->shape);
        }

        windowManager->window->display();
    }


    void fixCollisions() {
        for (auto *ball: *scene) {
            ball->fixScreenCollision(windowManager->window->getSize());
        }
    }

    explicit GameLoop(WindowManager *windowManager) {
        this->windowManager = windowManager;
        fillScene();
    }
};


#endif //HARDEND_GAMELOOP_H
