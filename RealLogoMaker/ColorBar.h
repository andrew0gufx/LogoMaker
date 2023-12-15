//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_COLORBAR_H
#define SFML_PROJECT_COLORBAR_H
#include "ColorPicker.h"

class ColorBar:public sf::Drawable, public sf::Transformable {
private:
    ColorPicker textColor;
    sf::Text textLabel;
    ColorPicker backgroundColor;
    sf::Text backgroundLabel;

public:
    ColorBar();
    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds();
    sf::Color getTextColor();
    sf::Color getBackgroundColor();
    void setTextColor(sf::Color color);
    void setBackgroundColor(sf::Color color);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_COLORBAR_H
