//
// Created by 16177 on 2022/4/25.
//

#include "Cursor.h"

void Cursor::toggleBlinkState() {
    if(blinkOn)
        blinkOn = false;
    else
        blinkOn = true;
    //flip boolean and switch the states
}

Cursor::Cursor() {
    sf::Vector2f vec(5, 50);
    cursor.setFillColor(sf::Color::White);
    cursor.setOutlineThickness(1);
    cursor.setSize(vec);
    blinkOn = false;
    clock.restart();
}

Cursor::Cursor(sf::Vector2f &size) {
    cursor.setFillColor(sf::Color::White);
    cursor.setOutlineThickness(1);
    cursor.setSize(size);
    blinkOn = false;
    clock.restart();
}

void Cursor::setPosition(float x, float y) {
    cursor.setPosition(x,y);
}

void Cursor::setSize(float x, float y) {
    cursor.setSize(sf::Vector2f(x,y));
}

sf::Vector2f Cursor::getSize() {
    return cursor.getSize();
}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(cursor);
}

void Cursor::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Cursor::update() {
    //switch the color, white to transparent or transparent to white
    if(clock.getElapsedTime() >= sf::milliseconds(500)){
        clock.restart();

        if(!blinkOn){
            cursor.setFillColor(sf::Color::White);
        }else{
            cursor.setFillColor(sf::Color::Transparent);
            cursor.setOutlineColor(sf::Color::Transparent);
        }

        toggleBlinkState();
    }
}
