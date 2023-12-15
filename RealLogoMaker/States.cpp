//
// Created by 16177 on 2022/4/3.
//

#include "States.h"

std::map<States::ObjectState, bool> States::states;
std::map<States::fonts, bool> States::fontsLoaded;
std::map<States::fonts, std::vector<sf::Font>> States::fontList;

int States::TEXT_SIZE = 30;
int States::WINDOW_WIDTH = 1500;
int States::WINDOW_HEIGHT = 1150;

std::map<States::Image, bool> States::loadImage;
sf::Texture States::fileTexture;
sf::Texture States::DirTexture;
std::string States::fileToOpen;
std::map<States::MenuBar, bool> States::status;

bool States::isStatusSet(States::MenuBar key) {
    return status[key];
}

void States::setStatus(States::MenuBar key, bool set) {
    status[key] = set;
}

void States::operator=(const States &other) {

}

bool States::isStateEnabled(States::ObjectState state) {
    return states[state];
}

void States::setStateEnable(States::ObjectState state, bool set) {
    states[state] = set;
}

bool States::isFontLoaded(States::fonts font) {
    return fontsLoaded[font];
}

void States::setFontLoad(States::fonts font, bool set) {
    fontsLoaded[font] = set;
    if(set){
        sf::Font f1;
        sf::Font f2;
        sf::Font f3;
        switch(font){
            case ARIAL:
                if(!f1.loadFromFile("Arial.ttf")){
                    std::cout << "Cannot load file\n";
                }
                if(!f2.loadFromFile("Arial Italic.ttf")){
                    std::cout << "Cannot load file\n";
                }
                if(!f3.loadFromFile("Arial Bold.ttf")){
                    std::cout << "Cannot load file\n";
                }
                fontList[font].push_back(f1);
                fontList[font].push_back(f2);
                fontList[font].push_back(f3);
                break;
            case VERDANA:
                if(!f1.loadFromFile("Verdana.ttf")){
                    std::cout << "Cannot load file\n";
                }
                if(!f2.loadFromFile("Verdana Italic.ttf")){
                    std::cout << "Cannot load file\n";
                }
                if(!f3.loadFromFile("Verdana Bold.ttf")){
                    std::cout << "Cannot load file\n";
                }
                fontList[font].push_back(f1);
                fontList[font].push_back(f2);
                fontList[font].push_back(f3);
                break;
            case TIME_NEW_ROMAN:
                if(!f1.loadFromFile("Times New Roman.ttf")){
                    std::cout << "Cannot load file\n";
                }
                if(!f2.loadFromFile("Times New Roman Italic.ttf")){
                    std::cout << "Cannot load file\n";
                }
                if(!f3.loadFromFile("Times New Roman Bold.ttf")){
                    std::cout << "Cannot load file\n";
                }
                fontList[font].push_back(f1);
                fontList[font].push_back(f2);
                fontList[font].push_back(f3);
                break;
        }
    }
}

sf::Font &States::getFont(States::fonts font, States::fontStyle style) {
    switch(font){
        case ARIAL:
            if(style == REGULAR){
                return fontList[font].at(0);
            }
            else if(style == ITALICS){
                return fontList[font].at(1);
            }
            else{
                return fontList[font].at(2);
            }
        case VERDANA:
            if(style == REGULAR){
                return fontList[font].at(0);
            }
            else if(style == ITALICS){
                return fontList[font].at(1);
            }
            else{
                return fontList[font].at(2);
            }
        case TIME_NEW_ROMAN:
            if(style == REGULAR){
                return fontList[font].at(0);
            }
            else if(style == ITALICS){
                return fontList[font].at(1);
            }
            else{
                return fontList[font].at(2);
            }
    }
}
