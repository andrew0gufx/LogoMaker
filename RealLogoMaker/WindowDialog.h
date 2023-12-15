//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_WINDOWDIALOG_H
#define SFML_PROJECT_WINDOWDIALOG_H
#include "GUIComponent.h"
#include "FileTree.h"
#include <experimental/filesystem>
//namespace fs = std::experimental::filesystem;


class WindowDialog {
private:
    sf::RenderWindow window;
    sf::Event event;

public:
    WindowDialog();
    void run();
};


#endif //SFML_PROJECT_WINDOWDIALOG_H
