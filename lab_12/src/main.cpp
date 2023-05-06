//
// Created by Sergei Kuzmenkov on 26.11.2022.
//
#include <vector>
#include <thread>
#include "WindowManager/WindowManager.h"
#include "RenderLoop/RenderLoop.h"
#include "MyText/AnimatedText.h"

void runRenderLoopThr(std::atomic_bool &isRunning, RenderLoop *renderLoop) {
    renderLoop->main(isRunning);
}

int main() {
    std::atomic_bool isRunning;
    isRunning = true;

    // Get string with spaces
    std::string text;
    std::getline(std::cin, text);

    float time;
    std::cin >> time;

    auto windowManager = new WindowManager;
    auto myText = new AnimatedText(text, time);
    auto renderLoop = new RenderLoop(windowManager, myText);

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