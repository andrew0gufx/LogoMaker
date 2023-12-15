//
// Created by 16177 on 2022/4/27.
//

#include "WindowDialog.h"
WindowDialog::WindowDialog(){

}


void WindowDialog::run(){
    window.create(sf::VideoMode({1000,1000}), "WindowDialog");
    FileTree tree;
    std::string path = "Project";
    tree.push("Project");
    for(auto& p : std::experimental::filesystem::directory_iterator(path)){
        tree.push(p.path().filename().string());
    }
    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            tree.addEventHandler(window, event);
            if(States::isStatusSet(States::OPEN_PROJ)){
                window.close();  // goes back to bottomMenu
            }
        }
        tree.update();
        window.clear();
        window.draw(tree);
        window.display();
    }
}