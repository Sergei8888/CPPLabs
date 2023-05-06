//
// Created by Sergei Kuzmenkov on 28.11.2022.
//
#include "SFML/Graphics.hpp"
#include <chrono>
#include <stdnoreturn.h>
#include "../WindowManager/WindowManager.h"
#include "../MyText/AnimatedText.h"

#ifndef HARDEND_GAMELOOP_H
#define HARDEND_GAMELOOP_H


class RenderLoop {
private:
    AnimatedText *animatedText;
    WindowManager *windowManager;
public:
    void main(std::atomic_bool &isRunning) {
        while (isRunning) {
            this->runIteration();
        }
    }

    void runIteration() {
        windowManager->window->clear(sf::Color(150, 150, 150));

        windowManager->window->draw(animatedText->getRenderTarget());

        windowManager->window->display();
    }

    explicit RenderLoop(WindowManager *windowManager, AnimatedText *animatedText) {
        this->animatedText = animatedText;
        this->windowManager = windowManager;
    }
};


#endif //HARDEND_GAMELOOP_H
