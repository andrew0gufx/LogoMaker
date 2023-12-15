//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_FONTSETTING_H
#define SFML_PROJECT_FONTSETTING_H
#include "DropdownMenu.h"
#include "GUIComponent.h"


class FontSetting:public sf::Drawable, public sf::Transformable {
private:
    sf::Text label;
    DropdownMenu fontList;
    DropdownMenu styleList;
public:
    FontSetting();
    void setPosition(float x, float y);
    void setFont(States::fonts font, States::fontStyle style);
    States::fonts getFont();
    States::fontStyle getStyle();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_FONTSETTING_H
