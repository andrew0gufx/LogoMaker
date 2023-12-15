//
// Created by 16177 on 2022/4/3.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() {
    box.setText("");
    appear = false;
}

DropdownMenu::DropdownMenu(std::string word) {
    box.setText(word);
    menu.add(word);
    setPosition(0,0);
    appear = false;
}

DropdownMenu::DropdownMenu(std::vector<std::string> vec) {
    x = 0;
    y = 0;
    box.setPosition(x,y);
    box.setText(vec.at(0));
    menu.setPosition(0,box.getGlobalBounds().height + 5);
    for(int i = 0; i < vec.size(); i++){
        menu.add(vec.at(i));
    }
    appear = false;
}

void DropdownMenu::resize(float x, float y) {
    box.setSize(x,y);
    menu.setSize(x,y);
    setPosition(box.getPosition().x,box.getPosition().y);
}

void DropdownMenu::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
    box.setPosition(x,y);
    menu.setPosition(x,y+box.getGlobalBounds().height);
}

void DropdownMenu::setText(std::string text) {
    box.setText(text);
}

void DropdownMenu::add(std::string item) {
    if(box.getText() == ""){
        box.setText(item);
    }
    menu.add(item);
    setPosition(box.getPosition().x,box.getPosition().y);
}

void DropdownMenu::reset(std::vector<std::string> vec) {

}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    if(appear)
        window.draw(menu);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<InputBox>::mouseClicked(box, window)){
        if(appear)
            appear = false;
        else
            appear = true;
    }
    else if(MouseEvents<ItemList>::mouseClicked(window,event)&&
            !MouseEvents<ItemList>::hovered(menu,window)){
        appear = false;
    }
    if(appear){
        menu.addEventHandler(window,event);
    }
    setPosition(x,y);
}

void DropdownMenu::update() {
    if(menu.isClicked()){
        menu.toggleClick();
        appear = false;
        box.setText(menu.getClicked());
        setPosition(x, y);
    }

    if(appear){
        box.setFillColor(sf::Color::Blue);
    }
    else{
        box.setFillColor(sf::Color::Transparent);
    }
    setPosition(x, y);
}

sf::Vector2f DropdownMenu::getPosition() {
    sf::Vector2f vec;
    vec.x = this->x;
    vec.y = this->y;
    return vec;
}

sf::FloatRect DropdownMenu::getGlobalBounds() {
    sf::Vector2f vec = getPosition();
    sf::FloatRect rec;
    rec.top = vec.y;
    rec.left = vec.x;
    rec.width = box.getGlobalBounds().width;
    rec.height = box.getGlobalBounds().height;
    return rec;
}

std::string DropdownMenu::getText() {
    return box.getText();
}
