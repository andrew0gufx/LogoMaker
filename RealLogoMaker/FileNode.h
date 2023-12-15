//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_FILENODE_H
#define SFML_PROJECT_FILENODE_H
#include "FileItem.h"
#include <map>


class FileNode: public sf::Drawable, public sf::Transformable {
private:
    FileItem data;
    std::map<std::string, FileNode*> children;
    void toggleChildren();
    bool state = false;
    std::string label;

public:
    // this is so I can use the iterator for the children map publicly
    typedef typename std::map<std::string, FileNode*>::iterator iterator;

    FileNode();
    FileNode(States::Image icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    // this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //does nothing now
    virtual void update();
    //does nothing now
    sf::FloatRect getGlobalBounds();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();

    void setData(const FileItem &data);

    std::map<std::string, FileNode*>& getChildren();

    void setPosition(float x, float y);

    //iterators
    iterator begin();
    iterator end();


    std::string getLabel() const;

    void addChild(States::Image icon, std::string label);

    bool isClicked();

};


#endif //SFML_PROJECT_FILENODE_H
