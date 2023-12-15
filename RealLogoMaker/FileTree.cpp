//
// Created by 16177 on 2022/4/27.
//

#include "FileTree.h"

FileTree::FileTree(){

}


void FileTree::push(std::string parent, std::string item){
    push(root, parent, item);
}


void FileTree::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(root){
        window.draw(*root);
    }
}


void FileTree::addEventHandler(sf::RenderWindow& window, sf::Event event){
    root->addEventHandler(window, event);

}


void FileTree::update(){
    int y = root->getGlobalBounds().top + root->getGlobalBounds().height;
    for(std::map<std::string, FileNode*>::iterator it = root->begin();
        it != root->end(); ++it)
    {
        it->second->setPosition(it->second->getPosition().x+50, y);
        if(it->second->isClicked()){
            y += it->second->getChildren().size() * it->second->getGlobalBounds().height;
        }
        y += it->second->getGlobalBounds().height;
    }
}


sf::FloatRect FileTree::getGlobalBounds(){
    return root->getGlobalBounds();
}


void FileTree::push(FileNode*& root, std::string parent, std::string item){
    // default: item == "NULL"
    if(!root){
        if(parent.find("txt") != std::string::npos)
            root = new FileNode(States::FILE_ICON, parent, {500,100}, initPosition);
        else
            root = new FileNode(States::DIRECTORY_ICON, parent, {500,100}, initPosition);
        return;
    }

    if(item == "NULL"){
        if(parent.find("txt") != std::string::npos)
            root->addChild(States::FILE_ICON, parent);
        else
            root->addChild(States::DIRECTORY_ICON, parent);
        return;
    }

    if(root->getChildren().empty() && parent == root->getLabel()){
        if(item.find("txt") != std::string::npos)
            root->addChild(States::FILE_ICON, item);
        else
            root->addChild(States::DIRECTORY_ICON, item);
    }
    else{
        for(std::map<std::string, FileNode*>::iterator it = root->begin();
            it != root->end(); ++it)
        {
            if(it->first == parent){
                if(item.find("txt") != std::string::npos)
                    it->second->addChild(States::FILE_ICON, item);
                else
                    it->second->addChild(States::DIRECTORY_ICON, item);
                return;
            }
            else if(!it->second->isLeaf()){
                push(it->second, parent, item);
            }
        }
    }

}
