//
// Created by 16177 on 2022/3/21.
//

#ifndef SFML_PROJECT_TEXTINPUTBOX_H
#define SFML_PROJECT_TEXTINPUTBOX_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextInputBox.h"
#include "MouseEvents.h"

class TextInputBox: public sf::RectangleShape{
public:
    TextInputBox();
    TextInputBox(const sf::Vector2f& size);
    TextInputBox(sf::Color color);
    TextInputBox(float width, float height, sf::Color color);

};


#endif //SFML_PROJECT_TEXTINPUTBOX_H
