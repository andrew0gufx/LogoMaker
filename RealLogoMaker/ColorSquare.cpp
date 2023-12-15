//
// Created by 16177 on 2022/4/27.
//

#include "ColorSquare.h"
ColorSquare::ColorSquare(sf::Color color){
    setFillColor(color);
    setSize({50,50});
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(1);
}

ColorSquare::ColorSquare()
        : ColorSquare(sf::Color::Red){

}


sf::Color ColorSquare::getColor(){
    return getFillColor();
}

void ColorSquare::setColor(sf::Color color){
    setFillColor(color);
    if(color == sf::Color::Black){
        setOutlineColor(sf::Color::White);
    }else{
        setOutlineColor(sf::Color::Black);
    }
}