//
// Created by 16177 on 2022/4/3.
//

#ifndef SFML_PROJECT_ITEM_H
#define SFML_PROJECT_ITEM_H
#include <iostream>
#include "MouseEvents.h"
#include "GUIComponent.h"


class Item: public sf::Drawable, public sf::Transformable{
public:
    Item(std::string msg, sf::Vector2f vec);
    Item(std::string msg);
    Item();
    //setter
    void setText(std::string msg);
    void setSize(float x, float y);
    void setPosition(float x, float y);
    void setFillColor(sf::Color color);
    void setFont(sf::Font& font);

    sf::FloatRect getGlobalBounds();
    //GUI
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    std::string getText() const;
    bool operator==(const Item& other);

private:
    sf::Text text;
    sf::RectangleShape box;

};



#endif //SFML_PROJECT_ITEM_H
