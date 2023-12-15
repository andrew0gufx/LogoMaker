//
// Created by 16177 on 2022/3/21.
//

#ifndef SFML_PROJECT_TEXTINPUT_H
#define SFML_PROJECT_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include"TextInputBox.h"
#include "Typing.h"
#include "MouseEvents.h"

class TextInput : public sf::Transformable, public sf::Drawable{
private:
    Typing text;
    TextInputBox textBox;
    sf::Text label;
public:
    TextInput();
    sf::FloatRect getGlobalBounds();
    std::string getLabel();
    std::string getString();

    void setLabel(std::string word);
    void setLabelSize(int size);
    void setPosition(float x, float y);
    void setLength(float len);
    void setSize(float x, float y);
    void setText(std::string text);

    void addEventHandler(sf::RenderWindow& window,sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //SFML_PROJECT_TEXTINPUT_H
