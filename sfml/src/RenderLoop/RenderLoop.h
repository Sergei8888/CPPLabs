//
// Created by Sergei Kuzmenkov on 28.11.2022.
//
#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <stdnoreturn.h>
#include "../WindowManager/WindowManager.h"

#ifndef HARDEND_GAMELOOP_H
#define HARDEND_GAMELOOP_H

class RenderLoop {
private:
    WindowManager *windowManager;
public:
    void main(std::atomic_bool &isRunning) {
        sf::Font font;
        if (!font.loadFromFile("Montserrat-Regular.ttf")) {
            std::cout << "Error loading font" << std::endl;
        }

        while (isRunning) {
            this->runIteration();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void runIteration() {
        windowManager->window->clear(sf::Color(150, 150, 150));

        windowManager->window->display();
    }

    explicit RenderLoop(WindowManager *windowManager) {
        this->windowManager = windowManager;
    }
};


#endif //HARDEND_GAMELOOP_H
