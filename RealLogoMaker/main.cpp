#include <SFML/Graphics.hpp>
#include "LogoMaker.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(States::WINDOW_WIDTH, States::WINDOW_HEIGHT), "LogoMaker");
    LogoMaker menu;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            menu.addEventHandler(window, event);
        }
        menu.update();
        window.clear();
        window.draw(menu);
        window.display();

    }
    return 0;
}

