//
// Created by 16177 on 2022/4/3.
//

#ifndef SFML_PROJECT_ITEMLIST_H
#define SFML_PROJECT_ITEMLIST_H
#include "Item.h"

class ItemList: public sf::Drawable, public sf::Transformable{
private:
    std::vector<Item> itemlist;
    std::string word;
    bool click;
public:
    ItemList();
    ItemList(std::vector<std::string> vec);   // given a vector of string
    sf::FloatRect getGlobalBounds();

    void setPosition(float x, float y);
    void setSize(float x, float y);   // x = width of a single Item inside list,
    // y = height of a single item
    void add(std::string item);      // add an item to the list
    std::string getClicked();
    bool isClicked();
    void toggleClick();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //SFML_PROJECT_ITEMLIST_H
