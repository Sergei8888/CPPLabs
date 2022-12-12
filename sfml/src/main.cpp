//
// Created by Sergei Kuzmenkov on 26.11.2022.
//
#include <vector>
#include <thread>
#include "WindowManager/WindowManager.h"
#include "GameLoop/GameLoop.h"

void runGameLoopThr(std::atomic_bool &isRunning, GameLoop *gameLoop) {
    gameLoop->main(isRunning);
}

int main() {
    std::atomic_bool isRunning;
    isRunning = true;

    auto windowManager = new WindowManager;
    auto gameLoop = new GameLoop(windowManager);

    std::thread gameLoopTread(runGameLoopThr, std::ref(isRunning), gameLoop);

    while (windowManager->window->isOpen()) {
        windowManager->handleWindowEvents();
    }

    // Terminating after window is closed
    isRunning = false;
    delete windowManager;
    delete gameLoop;
    gameLoopTread.join();
}