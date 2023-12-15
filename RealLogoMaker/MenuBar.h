//
// Created by 16177 on 2022/4/9.
//

#ifndef SFML_PROJECT_MENUBAR_H
#define SFML_PROJECT_MENUBAR_H
#include "Menu.h"
#include "WindowDialog.h"

class MenuBar: public sf::Drawable, public sf::Transformable{
public:
    MenuBar();

    void setPosition(float x, float y);
    void setSize(float x, float y);
    sf::FloatRect getGlobalBounds();

    void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

private:
    WindowDialog window;
    std::vector<Menu> bar;
    int index;
    bool isOpen;
};


#endif //SFML_PROJECT_MENUBAR_H
