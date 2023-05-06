//
// Created by Sergei Kuzmenkov on 26.11.2022.
//
#include <vector>
#include <thread>
#include "WindowManager/WindowManager.h"
#include "RenderLoop/RenderLoop.h"

void runRenderLoopThr(std::atomic_bool &isRunning, RenderLoop *renderLoop) {
    renderLoop->main(isRunning);
}

int main() {
    std::atomic_bool isRunning;
    isRunning = true;

    auto *windowManager = new WindowManager;
    auto renderLoop = new RenderLoop(windowManager);

    std::thread renderLoopThr(runRenderLoopThr, std::ref(isRunning), renderLoop);

    while (windowManager->window->isOpen()) {
        windowManager->handleWindowEvents();
    }

    // Terminating after window is closed
    isRunning = false;
    renderLoopThr.join();
    
    delete windowManager;
    delete renderLoop;
}