//
// Created by 16177 on 2022/4/9.
//

#include "MenuBar.h"
MenuBar::MenuBar(){
    Menu temp;
    temp.add("File");
    temp.add("Open Project");
    temp.add("Close Project");
    temp.add("New Project");
    temp.add("Save Project");
    temp.add("Quit");
    bar.push_back(temp);

    Menu temp2;
    temp2.add("Edit");
    temp2.add("Redo");
    temp2.add("Undo");
    bar.push_back(temp2);

    Menu temp3;
    temp3.add("Render");
    temp3.add("Export Image");
    bar.push_back(temp3);
    setPosition(0,0);

    isOpen = false;
    index = -1;
}


void MenuBar::setPosition(float x, float y){
    int index = 0;
    for(std::vector<Menu>::iterator i = bar.begin(); i < bar.end(); ++i){
        i->setPosition(x + index*i->getGlobalBounds().width, y);
        index++;
    }
}


void MenuBar::setSize(float x, float y){
    for(std::vector<Menu>::iterator i = bar.begin(); i < bar.end(); ++i){
        i->setSize(x, y);
    }
    setPosition(bar.begin()->getGlobalBounds().left, bar.begin()->getGlobalBounds().top);
}


sf::FloatRect MenuBar::getGlobalBounds(){
    sf::FloatRect rect;
    rect = bar.begin()->getGlobalBounds();
    rect.width *= bar.size();
    return rect;
}



void MenuBar::draw(sf::RenderTarget& window, sf::RenderStates state) const{
    for(Menu m: bar){
        window.draw(m);
    }
}


void MenuBar::addEventHandler(sf::RenderWindow& window, sf::Event event){

    for(std::vector<Menu>::iterator i = bar.begin(); i < bar.end(); ++i){
        i->addEventHandler(window, event);
    }

    bool temp = false;
    for(int k = 0; k < bar.size(); ++k){
        if(!bar.at(k).isHidden()){
            temp = true;
            index = k;
            break;
        }
    }
    isOpen = temp;
    if(!isOpen)
        index = -1;



    for(int j = 0; j < bar.size(); ++j){
        if(bar.at(j).titleHovered(window) && isOpen && j != index){
            bar.at(j).setHidden(false);
            bar.at(index).setHidden(true);
            index = j;
        }
    }
    setPosition(bar.at(0).getPosition().x, bar.at(0).getPosition().y);

}


void MenuBar::update(){
    for(std::vector<Menu>::iterator i = bar.begin(); i < bar.end(); ++i){
        i->update();
        if(i->isClicked()){
            std::string word = i->getClicked();
            if(word == "Open Project"){
                window.run();
            }
            else if(word == "Close Project"){
                States::setStatus(States::CLOSE_PROJ, true);
            }
            else if(word == "New Project"){
                std::cout << "New Project\n";
                States::setStatus(States::NEW_PROJ, true);
            }
            else if(word == "Save Project"){
                States::setStatus(States::SAVE_PROJ, true);
            }
            else if(word == "Quit"){
                States::setStatus(States::QUIT, true);
            }
            else if(word == "Redo"){
                std::cout << "Redo\n";
                States::setStatus(States::REDO, true);
            }
            else if(word == "Undo"){
                std::cout << "Undo\n";
                States::setStatus(States::UNDO, true);
            }
            else if(word == "Export Image"){
                States::setStatus(States::EXPORT_IMG, true);
            }
        }

    }
}