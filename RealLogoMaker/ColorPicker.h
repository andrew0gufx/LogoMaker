//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_COLORPICKER_H
#define SFML_PROJECT_COLORPICKER_H
#include "ColorGradient.h"
#include "ColorList.h"
#include "MouseEvents.h"


class ColorPicker:public sf::Drawable, public sf::Transformable {
private:
    ColorList list;
    ColorGradient gradient;
    ColorSquare square;
    sf::Color colorGot;
    bool showGradient;
    bool showList;
public:
    ColorPicker();
    sf::FloatRect getGlobalBounds();    // return globalBounds (globalBounds of single colorSquare
    void setPosition(float x, float y);    // setup position
    sf::Color getColor();    // get color that the user currently picked
    void setColor(sf::Color color);
    // GUI parts
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};


#endif //SFML_PROJECT_COLORPICKER_H
