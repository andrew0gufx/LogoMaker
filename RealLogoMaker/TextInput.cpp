//
// Created by 16177 on 2022/3/21.
//

#include "TextInput.h"

TextInput::TextInput() {
    label.setString("LOGO TEXT: ");
    label.setCharacterSize(25);

    if(!States::isFontLoaded(States::ARIAL))
        States::setFontLoad(States::ARIAL,true);
    label.setFont(States::getFont(States::ARIAL,States::REGULAR));
    text.setSize(textBox.getGlobalBounds().height - textBox.getOutlineThickness()*4);

    setPosition(label.getPosition().x, label.getPosition().y);
}

sf::FloatRect TextInput::getGlobalBounds(){
    sf::FloatRect rect;
    rect.top = label.getPosition().y;
    rect.left = label.getPosition().x;
    rect.width = textBox.getGlobalBounds().width;
    rect.height = textBox.getGlobalBounds().height + label.getCharacterSize() + 15;
    return rect;
}


std::string TextInput::getLabel(){
    std::string temp = "";
    temp += label.getString();
    return temp;
}


std::string TextInput::getString(){
    return text.getString();
}



void TextInput::setLabel(std::string word){
    label.setString(word);void setPosition(float x, float y);
}

void TextInput::setLabelSize(int size){
    label.setCharacterSize(size);
    setPosition(label.getPosition().x, label.getPosition().y);
}

void TextInput::setPosition(float x, float y){
    label.setPosition(x, y);
    textBox.setPosition(x, label.getPosition().y + label.getGlobalBounds().height + 15);
    text.setPosition(x + textBox.getOutlineThickness(),
                       textBox.getPosition().y + textBox.getOutlineThickness()/2);
}

void TextInput::setLength(float len){
    textBox.setSize({len, textBox.getSize().y});
    setPosition(label.getPosition().x, label.getPosition().y);
}

void TextInput::setSize(float x, float y){
    textBox.setSize({x, y});
    setPosition(label.getPosition().x, label.getPosition().y);
}

void TextInput::setText(std::string text1){
    text.setText(text1);
}


void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(textBox);
    window.draw(text);
    window.draw(label);
}

// from EventHandler
void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(MouseEvents<TextInputBox>::mouseClicked(textBox, window)){
        if(text.isHidden())
            text.toggleHidden();

    }else if(MouseEvents<TextInputBox>::mouseClicked(window, event) && !MouseEvents<TextInputBox>::hovered(textBox, window)){

        if(!text.isHidden())
            text.toggleHidden();

    }

    text.addEventHandler(window, event);
}

void TextInput::update(){
    text.update();
}