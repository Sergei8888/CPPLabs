//
// Created by Sergei Kuzmenkov on 26.11.2022.
//
#include <vector>
#include <thread>
#include "WindowManager/WindowManager.h"
#include "GameLoop/GameLoop.h"

int main() {
    auto windowManager = new WindowManager;

    std::thread gameLoopTread(&GameLoop::main, GameLoop(windowManager));

    while (windowManager->window->isOpen()) {
        windowManager->handleWindowEvents();
    }
}