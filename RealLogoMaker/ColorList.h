//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_COLORLIST_H
#define SFML_PROJECT_COLORLIST_H
#include "ColorSquare.h"

class ColorList:public sf::Drawable, public sf::Transformable {
private:
    sf::RectangleShape listBox;
    std::vector<ColorSquare> list;
public:
    ColorList();
    void setPosition(float x, float y); // setup position make sure they align as a list
    std::vector<ColorSquare>& getList();    // return the reference vector of color squares
    sf::FloatRect getGlobalBounds();    // return the listBox
    sf::Color getColorByIndex(int index);    // return the corresponding color based on the vector index
    // @Override
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_COLORLIST_H
