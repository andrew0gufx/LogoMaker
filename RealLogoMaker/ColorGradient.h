//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_COLORGRADIENT_H
#define SFML_PROJECT_COLORGRADIENT_H
#include "GUIComponent.h"


class ColorGradient: public sf::Drawable, public sf::Transformable {
private:
    sf::VertexArray gradients;  // array of points with diff. colors
    sf::RectangleShape background;
    sf::Color none;

public:
    ColorGradient(sf::Color color);
    ColorGradient();
    // adjust positions
    void setPosition(float x, float y);
    // globalBounds of the entire box
    sf::FloatRect getGlobalBounds();
    // getColor from the corresponding position/point
    sf::Color getColor(sf::Vector2i pos);
    // setup color of the gradient
    void setColor(sf::Color color);
    //@Override
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_COLORGRADIENT_H
