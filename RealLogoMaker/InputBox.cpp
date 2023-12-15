//
// Created by 16177 on 2022/4/28.
//

#include "InputBox.h"

InputBox::InputBox(std::string msg, sf::Vector2f vec, sf::Color color) {
    box.setSize(vec);
    box.setOutlineThickness(1);
    box.setOutlineColor(color);
    box.setFillColor(sf::Color::Transparent);

    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }
    text.setFont(States::getFont(States::ARIAL, States::REGULAR));
    text.setString(msg);
    text.setFillColor(color);
    text.setCharacterSize(vec.y/2);
    text.setPosition(getPosition().x + box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     getPosition().y + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.5);
}

InputBox::InputBox(std::string msg, sf::Vector2f vec)
        : InputBox(msg, vec, sf::Color::White){

}

InputBox::InputBox(std::string msg)
        : InputBox(msg, {250,50}, sf::Color::White){

}

InputBox::InputBox()
        : InputBox("Something", {250, 50}, sf::Color::White){

}

void InputBox::setText(std::string msg){
    text.setString(msg);
    setPosition(getPosition().x, getPosition().y);
}

void InputBox::setSize(float x, float y) {
    box.setSize({x,y});
    text.setCharacterSize(y/2);
}

void InputBox::setPosition(float x, float y) {
    box.setPosition(x, y);
    text.setPosition(x + box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     y + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.5);
}

sf::FloatRect InputBox::getGlobalBounds() {
    return box.getGlobalBounds();
}

void InputBox::setFillColor(sf::Color color) {
    box.setFillColor(color);
}

std::string InputBox::getText() {
    return text.getString();}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(text);
}
