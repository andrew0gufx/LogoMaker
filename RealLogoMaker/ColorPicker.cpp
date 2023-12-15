//
// Created by 16177 on 2022/4/27.
//

#include "ColorPicker.h"

ColorPicker::ColorPicker(){
    square.setColor(sf::Color::Red);

    // boolean vars indicate whether showing gradient/list
    showGradient = false;
    showList = false;


    // set color to default
    colorGot = sf::Color::Black;

    setPosition(square.getPosition().x, square.getPosition().y);
}



sf::FloatRect ColorPicker::getGlobalBounds(){
    return square.getGlobalBounds();
}


void ColorPicker::setPosition(float x, float y){
    square.setPosition(x, y);
    gradient.setPosition(x, y + square.getGlobalBounds().height);
    list.setPosition(x, y + square.getGlobalBounds().height);
}

sf::Color ColorPicker::getColor(){
    return square.getColor();
}

void ColorPicker::setColor(sf::Color color){
    square.setColor(color);
}


void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event){
    sf::Vector2i pos = sf::Mouse::getPosition(window);

    // click on the square
    if(MouseEvents<ColorSquare>::mouseClicked(square, window)){
        if(showList){
            showList = false;
        }else if(!showList){
            showList = true;
            if(showGradient){
                showGradient = false;
            }
        }
    }

        // click on the list
    else if(MouseEvents<ColorList>::mouseClicked(list, window) && showList){
        std::vector<ColorSquare>& vec = list.getList();
        for(int i = 0; i < vec.size(); i++){
            if(vec.at(i).getGlobalBounds().contains(pos.x, pos.y)){
                gradient.setColor(list.getColorByIndex(i));
                gradient.setPosition(square.getPosition().x,
                                     square.getPosition().y + square.getGlobalBounds().height);
                showList = false;
                showGradient = true;
            }
        }
    }

    // click on gradient
    else if(MouseEvents<ColorGradient>::mouseClicked(gradient, window) && showGradient){
        square.setColor(gradient.getColor(pos));
    }

    // click window but not square/list/gradient
    else if(MouseEvents<ColorSquare>::mouseClicked(window, event) &&
            !MouseEvents<ColorList>::hovered(list, window) &&
            !MouseEvents<ColorSquare>::hovered(square, window) &&
            !MouseEvents<ColorGradient>::hovered(gradient, window)){

        showGradient = false;
        showList = false;
    }
}


void ColorPicker::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(square);
    if(showGradient)
        window.draw(gradient);
    else if(showList)
        window.draw(list);

}
