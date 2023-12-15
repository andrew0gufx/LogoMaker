//
// Created by 16177 on 2022/4/27.
//

#ifndef SFML_PROJECT_NEWFILE_H
#define SFML_PROJECT_NEWFILE_H
#include "TextInput.h"
#include "InputBox.h"


class NewFile {
private:
    TextInput input;
    InputBox button;
    sf::RenderWindow window;
    sf::Event event;
    std::string result;
    sf::RenderTexture texture;

public:
    NewFile();
    //return the filename, null means no file
    std::string run();
};


#endif //SFML_PROJECT_NEWFILE_H
