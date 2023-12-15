//
// Created by 16177 on 2022/4/28.
//

#ifndef SFML_PROJECT_INPUTBOX_H
#define SFML_PROJECT_INPUTBOX_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"


class InputBox: public sf::Drawable, public sf::Transformable {
private:
    sf::RectangleShape box;
    sf::Text text;
public:
    InputBox(std::string msg, sf::Vector2f vec, sf::Color color);
    InputBox(std::string msg, sf::Vector2f vec);
    InputBox(std::string msg);
    InputBox();

    void setText(std::string msg);
    void setSize(float x, float y);
    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds();
    void setFillColor(sf::Color color);

    std::string getText();

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_INPUTBOX_H
