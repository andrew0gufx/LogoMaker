//
// Created by 16177 on 2022/4/25.
//

#ifndef SFML_PROJECT_CURSOR_H
#define SFML_PROJECT_CURSOR_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"


class Cursor: public sf::Drawable,public sf::Transformable {
private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    int blinkSpeed = 600;
    bool blinkOn;
    void toggleBlinkState();

public:
    Cursor();
    Cursor(sf::Vector2f& size);

    void setPosition(float x, float y);
    void setSize(float x, float y);
    sf::Vector2f getSize();

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_CURSOR_H
