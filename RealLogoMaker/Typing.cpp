//
// Created by 16177 on 2022/4/25.
//

#include "Typing.h"
Typing::Typing(){

    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }
    text.setFont(States::getFont(States::ARIAL, States::REGULAR));
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(cursor.getSize().y);
    text.setString("");
    hidden = true;

    setPosition(text.getPosition().x, text.getPosition().y);

}

void Typing::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(text);
    if(!hidden)
        window.draw(cursor);
}


void Typing::update(){
    cursor.update();
}

void Typing::setPosition(float x, float y){
    text.setPosition(x, y);
    cursor.setPosition(text.getPosition().x + text.getGlobalBounds().width + 5, y);
}

void Typing::setSize(float size){
    text.setCharacterSize(size);
    cursor.setSize(cursor.getSize().x, size);
    setPosition(text.getPosition().x, text.getPosition().y);
}


void Typing::setText(std::string text){
    this->text.setString(text);
}

void Typing::toggleHidden(){
    if(hidden)
        hidden = false;
    else
        hidden = true;
}


void Typing::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(hidden)
        return;

    if(event.type == sf::Event::TextEntered){
        if(event.text.unicode == 8){
            std::string temp = text.getString();
            temp.pop_back();
            text.setString(temp);

        }else if(event.text.unicode < 128){
            char input = static_cast<char>(event.text.unicode);
            std::string temp = text.getString();
            temp += input;
            text.setString(temp);
        }
    }
    setPosition(text.getPosition().x, text.getPosition().y);


}


std::string Typing::getString(){
    std::string temp = "";
    temp += text.getString();
    return temp;
}


bool Typing::isHidden(){
    return hidden;
}


sf::FloatRect Typing::getGlobalBounds(){
    sf::FloatRect rect;
    rect.left = text.getPosition().x;
    rect.top = text.getPosition().y;
    rect.width = text.getGlobalBounds().width + cursor.getSize().x + 5;
    rect.height = text.getGlobalBounds().height;
    return rect;
}
