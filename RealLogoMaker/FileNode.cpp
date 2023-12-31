//
// Created by 16177 on 2022/4/27.
//

#include "FileNode.h"

typedef typename std::map<std::string, FileNode*>::iterator iterator;

FileNode::FileNode()
        : FileNode(States::FILE_ICON, "File.txt", {500,100}, {0,0}){

}


FileNode::FileNode(States::Image icon, std::string text, sf::Vector2f size, sf::Vector2f position)
        : data{icon, text, size, position}{
    label = text;
}


void FileNode::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(data);
    if(state){
        for(std::map<std::string, FileNode*>::const_iterator it = children.begin();
            it != children.end(); ++it){
            window.draw(*(it->second));
        }
    }
}


void FileNode::addEventHandler(sf::RenderWindow& window, sf::Event event){
    data.addEventHandler(window, event);
    for(std::map<std::string, FileNode*>::const_iterator it = children.begin();
        it != children.end(); ++it){
        it->second->addEventHandler(window,event);

    }

    if(data.getFillColor() == sf::Color::Blue && !state)
        toggleChildren();
    if(MouseEvents<FileItem>::mouseClicked(data, window) && state)
        toggleChildren();
}


void FileNode::update(){
    int i = 0;
    for(std::map<std::string, FileNode*>::iterator it = children.begin();
        it != children.end(); ++it){
        it->second->setPosition(data.getPosition().x + 50, data.getPosition().y + data.getGlobalBounds().height*(i+1));
        i++;
    }
}


sf::FloatRect FileNode::getGlobalBounds(){
    return data.getGlobalBounds();
}


bool FileNode::isLeaf() const{
    return (label.find("File") != std::string::npos);
}


FileItem& FileNode::getData(){
    return data;
}


void FileNode::setData(const FileItem &data){
    this->data = data;
}


std::map<std::string, FileNode*>& FileNode::getChildren(){
    return children;
}


std::map<std::string, FileNode*>::iterator FileNode::begin(){
    return children.begin();
}


std::map<std::string, FileNode*>::iterator FileNode::end(){
    return children.end();
}


void FileNode::toggleChildren(){
    if(state)
        state = false;
    else
        state = true;

}


std::string FileNode::getLabel() const{
    return label;
}


void FileNode::setPosition(float x, float y){
    data.setPosition({x,y});
    update();
}



void FileNode::addChild(States::Image icon, std::string label){
    FileNode* temp = new FileNode(icon, label, {500,100}, {0,0});
    children[label] = temp;
    update();
}

bool FileNode::isClicked(){
    return state;
}
