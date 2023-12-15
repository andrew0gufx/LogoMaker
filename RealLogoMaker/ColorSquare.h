//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_COLORSQUARE_H
#define SFML_PROJECT_COLORSQUARE_H
#include "GUIComponent.h"


class ColorSquare: public sf::RectangleShape {
private:

public:
    ColorSquare(sf::Color color);
    ColorSquare();
    sf::Color getColor();
    void setColor(sf::Color color);
};


#endif //SFML_PROJECT_COLORSQUARE_H
