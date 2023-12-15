//
// Created by 16177 on 2022/4/3.
//

#include "Item.h"
Item::Item(std::string msg, sf::Vector2f vec){
    box.setSize(vec);
    box.setFillColor(sf::Color::Black);

    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }
    text.setFont(States::getFont(States::ARIAL, States::REGULAR));
    text.setString(msg);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(vec.y/2);
    text.setPosition(box.getPosition().x + box.getLocalBounds().width/2 - text.getLocalBounds().width/2,
                     box.getPosition().y + box.getLocalBounds().height/2 - text.getLocalBounds().height/1.5);
}


Item::Item(std::string msg)
        : Item(msg, {250,50}){

}


Item::Item()
        : Item("Something", {250, 50}){

}



void Item::setText(std::string msg){
    text.setString(msg);
}


void Item::setSize(float x, float y){
    box.setSize({x,y});
    text.setCharacterSize(y/2);
}

void Item::setPosition(float x, float y){
    box.setPosition(x, y);
    text.setPosition(x + box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     y + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.5);

}

void Item::setFillColor(sf::Color color){
    box.setFillColor(color);
}

void Item::setFont(sf::Font& font){
    text.setFont(font);
}

sf::FloatRect Item::getGlobalBounds(){
    return box.getGlobalBounds();
}

std::string Item::getText() const{
    return text.getString();
}

void Item::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    window.draw(text);

}

bool Item::operator==(const Item& other){
    return getText() == other.getText();
}