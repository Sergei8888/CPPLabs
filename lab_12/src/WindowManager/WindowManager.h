//
// Created by Sergei Kuzmenkov on 27.11.2022.
//
#include "SFML/Graphics.hpp"

#ifndef HARDEND_WINDOWMANAGER_H
#define HARDEND_WINDOWMANAGER_H


/*
 * Creates the application window and handles window events.
 */
class WindowManager {
private:
    int const INIT_WINDOW_HEIGHT = 1920;
    int const INIT_WINDOW_WIDTH = 1920;
public:
    sf::RenderWindow *window;

    void handleWindowEvents() const {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }
    };

    WindowManager() {
        window = new sf::RenderWindow(sf::VideoMode(INIT_WINDOW_HEIGHT, INIT_WINDOW_WIDTH), "SFML works!");
        window->setVerticalSyncEnabled(true);
    }

    ~WindowManager() {
        delete window;
    }
};


#endif //HARDEND_WINDOWMANAGER_H
