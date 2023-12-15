//
// Created by 16177 on 2022/4/28.
//

#include "LogoMaker.h"

LogoMaker::LogoMaker() {
    // setup background
    background.setSize({(float)States::WINDOW_WIDTH, (float)States::WINDOW_HEIGHT/3});
    update();
    setPosition(40, 0);
}

void LogoMaker::setPosition(float x, float y) {
    bar.setPosition(0, y);
    background.setPosition(0, bar.getPosition().y + bar.getGlobalBounds().height);
    menu.setPosition(x, background.getPosition().y + background.getGlobalBounds().height);
}

void LogoMaker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!closed){
        window.draw(background);
        window.draw(menu);
        window.draw(text);
        window.draw(shadow);
    }
    window.draw(bar);
}

void LogoMaker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(States::isStatusSet(States::QUIT)){
        window.close();
    }
    else if(States::isStatusSet(States::CLOSE_PROJ)){
        closed = true;
        States::setStatus(States::CLOSE_PROJ, false);
    }
    else if(States::isStatusSet(States::OPEN_PROJ)){
        closed = false;
    }
    else if(States::isStatusSet(States::NEW_PROJ)){
        menu.reset();
        States::setStatus(States::NEW_PROJ, false);
    }
    else if(States::isStatusSet(States::EXPORT_IMG)){
        std::string filename = filePrompt.run();
        if(filename != "NULL"){
            filename = "image/" + filename + ".png";
            sf::Texture texture;
            sf::Image imageTemp, image;
            texture.create(window.getSize().x, window.getSize().y);
            texture.update(window);
            imageTemp = texture.copyToImage();

            image.create(background.getGlobalBounds().width, background.getGlobalBounds().height, sf::Color::Transparent);
            image.copy(imageTemp, 0, 0,
                       sf::IntRect(background.getPosition().x, background.getPosition().y + bar.getGlobalBounds().height, background.getGlobalBounds().width, background.getGlobalBounds().height - bar.getGlobalBounds().height));


            image.saveToFile(filename);
        }
        States::setStatus(States::EXPORT_IMG, false);
    }

    menu.addEventHandler(window, event);
    bar.addEventHandler(window, event);
}

void LogoMaker::update() {
    menu.update();
    bar.update();


    // setup background
    sf::Color backgroundColor = menu.getBackGroundColor();
    backgroundColor.a = menu.getSliderValue(States::BACKGROUND_OPACITY);

    background.setFillColor(backgroundColor);


    // setup text
    sf::Color textColor = menu.getTextColor();
    textColor.a = menu.getSliderValue(States::TEXT_OPACITY);
    text.setString(menu.getLogoText());
    text.setFillColor(textColor);
    text.setCharacterSize(menu.getSliderValue(States::FONT_SIZE));
    text.setFont(menu.getFont());
    text.setPosition(menu.getSliderValue(States::TEXT_X_AXIS) + background.getPosition().x,
                     menu.getSliderValue(States::TEXT_Y_AXIS) + background.getPosition().y);
    text.setOrigin(text.getLocalBounds().width/2,
                   text.getLocalBounds().height/2);
    text.setRotation(menu.getSliderValue(States::TEXT_ROTATE));


    // setup shadow
    sf::Color shadowColor = sf::Color::White;
    shadowColor.a = menu.getSliderValue(States::SHADOW_OPACITY);
    shadow.setScale(1, (double)menu.getSliderValue(States::SKEW)/100*-1);
    shadow.setCharacterSize(menu.getSliderValue(States::FONT_SIZE));
    shadow.setFillColor(shadowColor);
    shadow.setString(menu.getLogoText());
    shadow.setFont(menu.getFont());
    shadow.setPosition(menu.getSliderValue(States::SHADOW_X_AXIS) + background.getPosition().x,
                       menu.getSliderValue(States::SHADOW_Y_AXIS) + background.getPosition().y);
    shadow.setOrigin(shadow.getLocalBounds().width/2,
                     shadow.getLocalBounds().height/2);
    shadow.setRotation(menu.getSliderValue(States::SHADOW_ROTATE));
}
