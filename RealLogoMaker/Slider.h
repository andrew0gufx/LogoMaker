//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_SLIDER_H
#define SFML_PROJECT_SLIDER_H
#include "GUIComponent.h"
#include "MouseEvents.h"


class Slider: public sf::Drawable, public sf::Transformable {
private:
    sf::Text label; // label of slider
    sf::Text curVal; // current value of slider
    sf::RectangleShape slider;
    sf::CircleShape knob;
    int relPos;

    void setupPosition();// adjust position of curVal, slider and knob

public:
    Slider();
    Slider(std::string label);
    Slider(std::string label, float length, float defaultVal = 0);

    void setPosition(float x, float y); // set position of slider
    void setMax(float max); // set max number of slider
    void setLabel(std::string label); // set label of slider
    void setCurrent(int num); // set currentVal

    int getCurVal();
    std::string getLabel();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_SLIDER_H
