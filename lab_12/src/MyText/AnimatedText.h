//
// Created by Sergei Kuzmenkov on 02.02.2023.
//
#include <thread>
#include <cmath>

#ifndef KURAMOTOMODEL_ANIMATEDTEXT_H
#define KURAMOTOMODEL_ANIMATEDTEXT_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

class AnimatedText {
private:
    sf::Color currentColor = sf::Color::Red;
    bool isRenderingStarted = false;
    sf::Font font;
    sf::Text *text;
    // Time to show text in seconds
    int showTime;
    std::atomic<int> letterCounter;

    static sf::Text *createText(const std::string &initialText, const sf::Font &initialFont) {
        auto textObject = new sf::Text(initialText, initialFont);
        textObject->setFillColor(sf::Color::Red);
        textObject->setCharacterSize(24);
        return textObject;
    }

public:
    sf::Text getRenderTarget() {
        if (!isRenderingStarted) {
            std::thread letterCounterThr([this] {
                                             const double timeToWait = ((double) showTime * 1000 / ((double) text->getString().getSize()) - 1);
                                             while (letterCounter < text->getString().getSize()) {
                                                 letterCounter++;
                                                 if (letterCounter != text->getString().getSize()) {
                                                     currentColor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
                                                     std::this_thread::sleep_for(std::chrono::milliseconds((int) timeToWait));
                                                 }
                                             }
                                         }
            );
            isRenderingStarted = true;
            letterCounterThr.detach();
        }

        sf::Text currentText = *this->text;
        currentText.setString(this->text->getString().substring(0, letterCounter));
        currentText.setFillColor(this->currentColor);

        return currentText;
    }

    explicit AnimatedText(const std::string &text = "Hello world!", int showTime = 3) {
        this->letterCounter = 0;

        if (!this->font.loadFromFile("Montserrat-Regular.ttf")) {
            std::cout << "Error while loading font, please check font path";
            std::exit(1);
        }

        this->text = createText(text, this->font);
        this->showTime = showTime;
    }
};

#endif //KURAMOTOMODEL_ANIMATEDTEXT_H
