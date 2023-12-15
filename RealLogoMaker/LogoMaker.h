//
// Created by 16177 on 2022/4/28.
//

#ifndef SFML_PROJECT_LOGOMAKER_H
#define SFML_PROJECT_LOGOMAKER_H
#include "BottomMenu.h"
#include "MenuBar.h"

class LogoMaker: public sf::Drawable, public sf::Transformable {
private:
    MenuBar bar;
    BottomMenu menu;
    sf::Text text;
    sf::Text shadow;
    sf::RectangleShape background;
    NewFile filePrompt;
    bool closed = false;
public:
    LogoMaker();
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_LOGOMAKER_H
