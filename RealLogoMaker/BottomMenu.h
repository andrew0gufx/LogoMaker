//
// Created by 16177 on 2022/4/25.
//

#ifndef SFML_PROJECT_BOTTOMMENU_H
#define SFML_PROJECT_BOTTOMMENU_H
#include "Slider.h"
#include "TextInput.h"
#include "ColorBar.h"
#include "FontSetting.h"
#include "NewFile.h"
#include <fstream>

class BottomMenu: public sf::Drawable,public sf::Transformable {
private:
    std::map<States::sliderType, int> sliderIndex;// <sliderType, index of slider in vector>
    std::vector<Slider> sliders;
    TextInput inputBox;
    ColorBar bar;
    FontSetting fontList;
    NewFile filePrompt;
public:
    BottomMenu();
    void setPosition(float x, float y);

    int getSliderValue(States::sliderType key);
    std::string getLogoText();
    sf::Color getTextColor();
    sf::Color getBackGroundColor();
    sf::Font& getFont();
    void setSliderValue(States::sliderType key, int value);
    void setLogoText(std::string logo);
    void setTextColor(sf::Color color);
    void setBackGroundColor(sf::Color color);
    void setFont(States::fonts font, States::fontStyle style);
    void reset();       // set values to default

    // GUI
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_BOTTOMMENU_H
