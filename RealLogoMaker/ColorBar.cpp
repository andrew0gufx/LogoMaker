//
// Created by 16177 on 2022/4/27.
//

#include "ColorBar.h"

ColorBar::ColorBar() {
    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }
    textLabel.setFont(States::getFont(States::ARIAL, States::REGULAR));
    backgroundLabel.setFont(States::getFont(States::ARIAL, States::REGULAR));
    textLabel.setCharacterSize(textColor.getGlobalBounds().height/3*2);
    backgroundLabel.setCharacterSize(textColor.getGlobalBounds().height/3*2);
    textLabel.setFillColor(sf::Color::White);
    backgroundLabel.setFillColor(sf::Color::White);
    textLabel.setString("Text Color");
    backgroundLabel.setString("Background Color");

    backgroundColor.setColor(sf::Color::Black);
    textColor.setColor(sf::Color::Red);

    // setup initial pos
    setPosition(0, 0);
}

void ColorBar::setPosition(float x, float y) {
    int horiPadding = 20;
    textColor.setPosition(x, y);
    textLabel.setPosition(x + textColor.getGlobalBounds().width + horiPadding, y);
    backgroundColor.setPosition(textLabel.getPosition().x + textLabel.getGlobalBounds().width + horiPadding*2, y);
    backgroundLabel.setPosition(backgroundColor.getGlobalBounds().left + backgroundColor.getGlobalBounds().width + horiPadding, y);
}

sf::FloatRect ColorBar::getGlobalBounds() {
    sf::FloatRect rect;
    rect.top = textColor.getGlobalBounds().top;
    rect.left = textColor.getGlobalBounds().left;
    rect.width = textColor.getGlobalBounds().width + textLabel.getGlobalBounds().width +
            backgroundColor.getGlobalBounds().width + backgroundLabel.getGlobalBounds().width + 20*4;
    rect.height = textColor.getGlobalBounds().height;

    return rect;
}

sf::Color ColorBar::getTextColor() {
    return textColor.getColor();
}

sf::Color ColorBar::getBackgroundColor() {
    return backgroundColor.getColor();
}

void ColorBar::setTextColor(sf::Color color) {
    textColor.setColor(color);
}

void ColorBar::setBackgroundColor(sf::Color color) {
    backgroundColor.setColor(color);
}

void ColorBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(textColor);
    window.draw(textLabel);
    window.draw(backgroundColor);
    window.draw(backgroundLabel);
}

void ColorBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textColor.addEventHandler(window, event);
    backgroundColor.addEventHandler(window, event);
}

void ColorBar::update() {

}
