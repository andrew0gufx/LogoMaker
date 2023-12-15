//
// Created by 16177 on 2022/4/25.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

class States{
public:
    enum ObjectState{APPEAR, CLICKED, LASTSTATE};
    //slider menu for bottom menu
    enum sliderType{TEXT_OPACITY, FONT_SIZE, SKEW,SHADOW_OPACITY,
    BACKGROUND_OPACITY, TEXT_ROTATE, SHADOW_ROTATE, TEXT_X_AXIS,
    TEXT_Y_AXIS, SHADOW_X_AXIS, SHADOW_Y_AXIS};
    //font
    enum fonts{ARIAL, VERDANA, TIME_NEW_ROMAN};
    enum fontStyle{REGULAR, BOLD, ITALICS};
    //colors
    enum colors{RED,YELLOW,GREEN,BLUE,LIGHTBLUE,PURPLE,BLACK,WHITE};
    //fileTree image
    enum Image { FILE_ICON, DIRECTORY_ICON };
    enum MenuBar {OPEN_PROJ, CLOSE_PROJ, NEW_PROJ, SAVE_PROJ, QUIT, REDO, UNDO, EXPORT_IMG};
    static std::map<MenuBar, bool> status;
    static std::map<Image, bool> loadImage;
    static bool isStatusSet(MenuBar key);
    static void setStatus(MenuBar key, bool set);
    static std::string fileToOpen;
    static sf::Texture fileTexture;
    static sf::Texture DirTexture;

    // global accessors and mutators
    void operator=(const States& other);
    static bool isStateEnabled(ObjectState state);
    static void setStateEnable(ObjectState state, bool set);

    static bool isFontLoaded(fonts font);
    static void setFontLoad(fonts font, bool set);
    static sf::Font& getFont(fonts font, fontStyle style);

    static int TEXT_SIZE;
    static int WINDOW_WIDTH;
    static int WINDOW_HEIGHT;


private:
    static std::map<ObjectState, bool> states;
    static std::map<fonts, bool> fontsLoaded;
    static std::map<fonts, std::vector<sf::Font>> fontList;

};

#endif //SFML_PROJECT_STATES_H
