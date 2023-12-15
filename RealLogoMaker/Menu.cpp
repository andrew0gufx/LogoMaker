//
// Created by 16177 on 2022/4/9.
//

#include "Menu.h"
Menu::Menu(){
    title.setText("");
    setPosition(title.getGlobalBounds().left, title.getGlobalBounds().top);
    appear = false;
    clicked = false;
}


void Menu::setPosition(float x, float y){
    title.setPosition(x, y);
    list.setPosition(x, y + title.getGlobalBounds().height);
}


void Menu::setSize(float x, float y){
    title.setSize(x, y);
    list.setSize(x, y);
    setPosition(title.getGlobalBounds().left, title.getGlobalBounds().top);
}


sf::FloatRect Menu::getGlobalBounds(){
    sf::FloatRect rec;
    rec.top = title.getGlobalBounds().top;
    rec.left = title.getGlobalBounds().left;
    rec.width = title.getGlobalBounds().width;
    rec.height = title.getGlobalBounds().height ;
    return rec;
}


void Menu::setString(std::string title){
    this->title.setText(title);
    setPosition(this->title.getGlobalBounds().left, this->title.getGlobalBounds().top);
}


void Menu::add(std::string word){
    if(title.getText() == ""){
        title.setText(word);
    }else{
        list.add(word);
    }

    setPosition(title.getGlobalBounds().left, title.getGlobalBounds().top);
}


void Menu::draw(sf::RenderTarget& window, sf::RenderStates state) const{
    window.draw(title);
    if(appear)
        window.draw(list);
}


void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event){

    if(MouseEvents<Item>::mouseClicked(title, window)){
        if(appear){
            appear = false;
            title.setFillColor(sf::Color::Transparent);
        }else{
            appear = true;
            title.setFillColor(sf::Color::Blue);
        }
    }else if(MouseEvents<ItemList>::mouseClicked(window, event) &&
             !MouseEvents<ItemList>::hovered(list, window)){
        appear = false;
        title.setFillColor(sf::Color::Transparent);
    }

    if(appear){
        list.addEventHandler(window, event);
    }
    setPosition(title.getGlobalBounds().left, title.getGlobalBounds().top);
}


void Menu::update(){
    if(list.isClicked()){
        appear = false;
        clicked = true;
        list.toggleClick();
        word = list.getClicked();
        setPosition(title.getGlobalBounds().left, title.getGlobalBounds().top);
        title.setFillColor(sf::Color::Transparent);
    }
    setPosition(title.getGlobalBounds().left, title.getGlobalBounds().top);
}

bool Menu::isClicked(){
    return clicked;
}


std::string Menu::getClicked(){
    clicked = false;
    return word;
}

bool Menu::isHidden(){
    return !appear;
}


void Menu::setHidden(bool h){
    appear = !h;
    if(!appear){
        title.setFillColor(sf::Color::Transparent);
    }else{
        title.setFillColor(sf::Color::Blue);
    }
}

bool Menu::titleHovered(sf::RenderWindow& window){
    return (MouseEvents<Item>::hovered(title, window));
}

bool Menu::titleClicked(sf::RenderWindow& window){
    return (MouseEvents<Item>::mouseClicked(title, window));
}