//
// Created by 16177 on 2022/4/25.
//

#ifndef SFML_PROJECT_TYPING_H
#define SFML_PROJECT_TYPING_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "Cursor.h"
#include "TextInputBox.h"
#include <iostream>


class Typing: public sf::Drawable,public sf::Transformable {
private:
    Cursor cursor;
    sf::Text text;
    bool hidden;
public:
    Typing();

    void setPosition(float x, float y);
    void toggleHidden();
    void setSize(float size);
    void setText(std::string text);

    std::string getString();
    bool isHidden();
    sf::FloatRect getGlobalBounds();

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //SFML_PROJECT_TYPING_H
