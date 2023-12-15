//
// Created by 16177 on 2022/4/27.
//

#include "Slider.h"

void Slider::setupPosition() {
    float padding = 15;

    this->slider.setPosition(padding + label.getPosition().x+label.getGlobalBounds().width,
                             label.getPosition().y+label.getCharacterSize()/4*3-slider.getGlobalBounds().height/2);

    this->knob.setPosition(slider.getPosition().x + relPos - knob.getRadius(),
                           slider.getPosition().y+slider.getGlobalBounds().height/2-knob.getRadius());

    this->curVal.setPosition(slider.getPosition().x + slider.getGlobalBounds().width + padding + 10,
                             label.getPosition().y+3);
}

Slider::Slider()
        :Slider("Slider", 500){

}

Slider::Slider(std::string label)
        :Slider(label, 500){

}

Slider::Slider(std::string label, float length, float defaultVal) {
    relPos = defaultVal;

    // setup font
    if(!States::isFontLoaded(States::ARIAL)){
        States::setFontLoad(States::ARIAL, true);
    }

    // setup label and curVal
    this->label.setFont(States::getFont(States::ARIAL, States::REGULAR));
    this->label.setCharacterSize(States::TEXT_SIZE);
    this->label.setFillColor(sf::Color::White);
    this->label.setString(label+":  ");
    this->curVal.setFont(States::getFont(States::ARIAL, States::REGULAR));
    this->curVal.setCharacterSize(States::TEXT_SIZE);
    this->curVal.setFillColor(sf::Color::White);
    this->curVal.setString(std::to_string(relPos));

    // setup bar
    this->slider.setSize({length, 3});
    this->slider.setFillColor(sf::Color::White);

    // setup knob
    this->knob.setRadius(15);
    this->knob.setFillColor(sf::Color::Red);

    // initialize position
    setupPosition();
}

void Slider::setPosition(float x, float y) {
    this->label.setPosition(x, y);
    setupPosition();
}

void Slider::setMax(float max) {
    this->slider.setSize({max, this->slider.getSize().y});
    setupPosition();
}

void Slider::setLabel(std::string label) {
    this->label.setString(label+": ");
    setupPosition();
}

void Slider::setCurrent(int num) {
    this->relPos = num;
    curVal.setString(std::to_string(relPos));
    setupPosition();
}

int Slider::getCurVal() {
    return relPos;
}

std::string Slider::getLabel() {
    std::string temp = label.getString();
    return temp;
}

sf::FloatRect Slider::getGlobalBounds() {
    sf::FloatRect rect;
    rect.left = label.getPosition().x;
    rect.top = label.getPosition().y;
    rect.width = label.getGlobalBounds().width + slider.getGlobalBounds().width + curVal.getGlobalBounds().width+40;
    rect.height = label.getCharacterSize();
    return rect;
}

sf::Vector2f Slider::getPosition() {
    return label.getPosition();
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(slider);
    window.draw(knob);
    window.draw(curVal);
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::CircleShape>::draggedOver(knob, window, event)){
        knob.setFillColor(sf::Color::Green);
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        this->relPos = mousePos.x - slider.getPosition().x;

        // set boundary
        if(relPos > slider.getSize().x)
            relPos = slider.getSize().x;
        else if(relPos < 0)
            relPos = 0;

        // update curVal
        this->curVal.setString(std::to_string(relPos));

        setupPosition();
    }else{
        knob.setFillColor(sf::Color::White);
    }
}

void Slider::update() {

}
