//
// Created by 16177 on 2022/4/27.
//

#include "FontSetting.h"

FontSetting::FontSetting() {
    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }
    label.setFont(States::getFont(States::ARIAL, States::REGULAR));
    label.setCharacterSize(20);
    label.setFillColor(sf::Color::White);
    label.setString("Font Setting");

    fontList.add("Arial");
    fontList.add("Verdana");
    fontList.add("Times New Roman");

    styleList.add("Regular");
    styleList.add("Italics");
    styleList.add("Bold");

    setPosition(0, 0);
}

void FontSetting::setPosition(float x, float y) {
    label.setPosition(x, y);
    fontList.setPosition(x, y + label.getGlobalBounds().height + 15);
    styleList.setPosition(x + fontList.getGlobalBounds().width + 30, fontList.getPosition().y);
}

void FontSetting::setFont(States::fonts font, States::fontStyle style) {
    if(font == States::ARIAL){
        fontList.setText("Arial");
    }
    else if(font == States::VERDANA){
        fontList.setText("Verdana");
    }
    else{
        fontList.setText("Times New Roman");
    }

    if(style == States::REGULAR){
        styleList.setText("Regular");
    }
    else if(style == States::BOLD){
        styleList.setText("Bold");
    }
    else{
        styleList.setText("Italics");
    }

    setPosition(label.getPosition().x, label.getPosition().y);
}

States::fonts FontSetting::getFont() {
    std::string font = fontList.getText();
    if(font == "Arial"){
        if(!States::isFontLoaded(States::ARIAL)){
            States::setFontLoad(States::ARIAL, true);
        }
        return States::ARIAL;
    }
    else if(font == "Verdana"){
        if(!States::isFontLoaded(States::VERDANA)){
            States::setFontLoad(States::VERDANA, true);
        }
        return States::VERDANA;
    }
    else{
        if(!States::isFontLoaded(States::TIME_NEW_ROMAN)){
            States::setFontLoad(States::TIME_NEW_ROMAN, true);
        }
        return States::TIME_NEW_ROMAN;
    }
}

States::fontStyle FontSetting::getStyle() {
    std::string style = styleList.getText();
    if(style == "Regular"){
        return States::REGULAR;
    }
    else if(style == "Italics"){
        return States::ITALICS;
    }
    else{
        return States::BOLD;
    }
}

sf::FloatRect FontSetting::getGlobalBounds() {
    sf::FloatRect rect;
    rect.left = label.getPosition().x;
    rect.top = label.getPosition().y;
    rect.height = label.getCharacterSize() + 15 + fontList.getGlobalBounds().height;
    rect.width = fontList.getGlobalBounds().width + 30 + styleList.getGlobalBounds().width;
    return rect;
}

sf::Vector2f FontSetting::getPosition() {
    return label.getPosition();
}

void FontSetting::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(fontList);
    window.draw(styleList);
}

void FontSetting::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    fontList.addEventHandler(window, event);
    styleList.addEventHandler(window, event);
}

void FontSetting::update() {
    fontList.update();
    styleList.update();
}
