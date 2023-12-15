//
// Created by 16177 on 2022/4/3.
//

#ifndef SFML_PROJECT_DROPDOWNMENU_H
#define SFML_PROJECT_DROPDOWNMENU_H
#include "ItemList.h"
#include "InputBox.h"
#include "GUIComponent.h"

class DropdownMenu: public sf::Drawable,public sf::Transformable{
public:
    DropdownMenu();
    DropdownMenu(std::string word);
    DropdownMenu(std::vector<std::string> vec);// given list of string
    //setter
    void resize(float x, float y);
    void setPosition(float x, float y);
    void setText(std::string text);
    void add(std::string item);
    void reset(std::vector<std::string> vec);
    //GUI
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    std::string getText();

private:
    //Snapshot snap;
    InputBox box;
    ItemList menu;
    float x, y;  // record the position
    bool appear;
};


#endif //SFML_PROJECT_DROPDOWNMENU_H
