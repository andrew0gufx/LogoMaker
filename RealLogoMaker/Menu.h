//
// Created by 16177 on 2022/4/9.
//

#ifndef SFML_PROJECT_MENU_H
#define SFML_PROJECT_MENU_H
#include "ItemList.h"


class Menu: public sf::Drawable, public sf::Transformable{
public:
    Menu();

    void setPosition(float x, float y);
    void setSize(float x, float y);
    sf::FloatRect getGlobalBounds();
    void setString(std::string title);
    void add(std::string word);
    bool isHidden();
    void setHidden(bool h);
    bool titleHovered(sf::RenderWindow& window);
    bool titleClicked(sf::RenderWindow& window);
    bool isClicked();
    std::string getClicked();

    void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();


private:
    Item title;
    ItemList list;
    std::string word;
    bool appear;
    bool clicked;
};


#endif //SFML_PROJECT_MENU_H
