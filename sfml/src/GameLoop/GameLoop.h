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

    void main(std::atomic_bool &isRunning) {
        while (isRunning) {
            this->runIteration();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void fillScene() const {
        auto circle = ScieneManager::createCircleFigure();
        auto rectangle = ScieneManager::createRectangleFigure();

        scene->push_back(circle);
        scene->push_back(rectangle);
    }

    void runIteration() {
        windowManager->window->clear(sf::Color(150, 150, 150));

        for (auto *ball: *scene) {
            ball->updatePosition();
            ball->fixScreenCollision(windowManager->window->getSize());
            windowManager->window->draw(*ball->shape);
        }

        windowManager->window->display();
    }

    explicit GameLoop(WindowManager *windowManager) {
        this->windowManager = windowManager;
        fillScene();
    }

    ~GameLoop() {
        for (auto *ball: *scene) {
            delete ball;
        }

        delete scene;
    }
};


#endif //HARDEND_GAMELOOP_H
