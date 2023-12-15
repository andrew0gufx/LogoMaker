//
// Created by 16177 on 2022/4/27.
//

#include "ColorList.h"
ColorList::ColorList(){
    int padding = 5;

    // add colorSquares to the list
    ColorSquare red(sf::Color::Red);
    list.push_back(red);

    ColorSquare yellow(sf::Color::Yellow);
    list.push_back(yellow);

    ColorSquare green(sf::Color::Green);
    list.push_back(green);

    ColorSquare cyan(sf::Color::Cyan);
    list.push_back(cyan);

    ColorSquare blue(sf::Color::Blue);
    list.push_back(blue);

    ColorSquare magenta(sf::Color::Magenta);
    list.push_back(magenta);

    ColorSquare black(sf::Color::Black);
    list.push_back(black);

    ColorSquare white(sf::Color::White);
    list.push_back(white);

    // setup listBox
    listBox.setSize({
                            red.getGlobalBounds().width*4 + 5*padding,
                            red.getGlobalBounds().height*2 + 3*padding
                    });
    listBox.setFillColor(sf::Color::White);


    // set positions
    setPosition(red.getPosition().x, red.getPosition().y);
}


void ColorList::setPosition(float x, float y){
    int padding = 5;
    listBox.setPosition(x, y);
    for(int i = 0; i < list.size(); i++){
        list.at(i).setPosition(
                x + padding*(1+i%4) + list.at(i).getGlobalBounds().width*(i%4)+1,
                y + padding*(1+i/4) + list.at(i).getGlobalBounds().height*(i/4)+1
        );
    }
}


std::vector<ColorSquare>& ColorList::getList(){
    return list;
}


sf::FloatRect ColorList::getGlobalBounds(){
    return listBox.getGlobalBounds();
}

sf::Color ColorList::getColorByIndex(int index){
    return list.at(index).getColor();
}


void ColorList::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(listBox);
    for(int i = 0; i < list.size(); i++){
        window.draw(list.at(i));
    }
}