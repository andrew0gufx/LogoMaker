//
// Created by 16177 on 2022/4/25.
//

#include "BottomMenu.h"

BottomMenu::BottomMenu() {
// adding sliders
    int index = 0;

    Slider textRotate = Slider("Text Rotate", 360);
    sliderIndex[States::TEXT_ROTATE] = index++;
    sliders.push_back(textRotate);

    Slider shadowRotate = Slider("Shadow Rotate", 360);
    sliderIndex[States::SHADOW_ROTATE] = index++;
    sliders.push_back(shadowRotate);

    Slider textOpa = Slider("Text Opacity", 255, 255);
    sliderIndex[States::TEXT_OPACITY] = index++;
    sliders.push_back(textOpa);

    Slider fontSize = Slider("Font Size", 150, 70);
    sliderIndex[States::FONT_SIZE] = index++;
    sliders.push_back(fontSize);

    Slider skew = Slider("Skew", 100, 55);
    sliderIndex[States::SKEW] = index++;
    sliders.push_back(skew);

    Slider shadowOpa = Slider("Shadow Opacity", 255, 255);
    sliderIndex[States::SHADOW_OPACITY] = index++;
    sliders.push_back(shadowOpa);

    Slider backgroundOpa = Slider("Background Opacity", 255, 255);
    sliderIndex[States::BACKGROUND_OPACITY] = index++;
    sliders.push_back(backgroundOpa);

    Slider xAxis = Slider("Text X-Axis", 1000, 500);
    sliderIndex[States::TEXT_X_AXIS] = index++;
    sliders.push_back(xAxis);

    Slider yAxis = Slider("Text Y-Axis", 1000, 164);
    sliderIndex[States::TEXT_Y_AXIS] = index++;
    sliders.push_back(yAxis);

    Slider shadowXAxis = Slider("Shadow X-Axis", 1000, 509);
    sliderIndex[States::SHADOW_X_AXIS] = index++;
    sliders.push_back(shadowXAxis);

    Slider ShadowYAxis = Slider("Shadow Y-Axis", 1000, 250);
    sliderIndex[States::SHADOW_Y_AXIS] = index++;
    sliders.push_back(ShadowYAxis);



    // setup positions
    setPosition(40, States::WINDOW_HEIGHT/2);
}

void BottomMenu::setPosition(float x, float y) {
    int vertPadding = 30;
    int horiPadding = 60;

    inputBox.setPosition(x, y);

    fontList.setPosition(x, y + inputBox.getGlobalBounds().height + 10);
    bar.setPosition(fontList.getPosition().x + fontList.getGlobalBounds().width + horiPadding*2,
                    fontList.getPosition().y + 30);


    sliders.at(0).setPosition(x, bar.getGlobalBounds().top + bar.getGlobalBounds().height + 20);
    sliders.at(1).setPosition(sliders.at(0).getPosition().x + sliders.at(0).getGlobalBounds().width + horiPadding,
                              sliders.at(0).getPosition().y );


    sliders.at(2).setPosition(x, sliders.at(0).getPosition().y + sliders.at(0).getGlobalBounds().height + vertPadding);
    sliders.at(3).setPosition(sliders.at(2).getPosition().x + sliders.at(2).getGlobalBounds().width + horiPadding,
                              sliders.at(2).getPosition().y);
    sliders.at(4).setPosition(sliders.at(3).getPosition().x + sliders.at(3).getGlobalBounds().width + horiPadding,
                              sliders.at(2).getPosition().y);


    sliders.at(5).setPosition(x,
                              sliders.at(2).getPosition().y + sliders.at(2).getGlobalBounds().height + vertPadding);
    sliders.at(6).setPosition(sliders.at(5).getPosition().x + sliders.at(5).getGlobalBounds().width + horiPadding,
                              sliders.at(5).getPosition().y);


    sliders.at(7).setPosition(x,
                              sliders.at(6).getPosition().y + sliders.at(6).getGlobalBounds().height + vertPadding);
    sliders.at(8).setPosition(x,
                              sliders.at(7).getPosition().y + sliders.at(7).getGlobalBounds().height + vertPadding);
    sliders.at(9).setPosition(x,
                              sliders.at(8).getPosition().y + sliders.at(8).getGlobalBounds().height + vertPadding);
    sliders.at(10).setPosition(x,
                               sliders.at(9).getPosition().y + sliders.at(9).getGlobalBounds().height + vertPadding);
}

int BottomMenu::getSliderValue(States::sliderType key) {
    int index = sliderIndex[key];
    Slider& slider = sliders.at(index);
    if(key == States::TEXT_X_AXIS || key == States::SHADOW_X_AXIS){
        double correspondVal = (double)slider.getCurVal()/1000*States::WINDOW_WIDTH;
        return correspondVal;
    }else if(key == States::TEXT_Y_AXIS || key == States::SHADOW_Y_AXIS){
        double correspondVal = (double)slider.getCurVal()/1000*States::WINDOW_HEIGHT;
        return correspondVal;
    }
    return slider.getCurVal();
}

std::string BottomMenu::getLogoText() {
    return inputBox.getString();
}

sf::Color BottomMenu::getTextColor() {
    return bar.getTextColor();
}

sf::Color BottomMenu::getBackGroundColor() {
    return bar.getBackgroundColor();
}

sf::Font &BottomMenu::getFont() {
    return States::getFont(fontList.getFont(), fontList.getStyle());
}

void BottomMenu::setSliderValue(States::sliderType key, int value) {
    sliderIndex[key] = value;
}

void BottomMenu::setLogoText(std::string logo) {
    inputBox.setLabel(logo);
}

void BottomMenu::setTextColor(sf::Color color) {
    bar.setTextColor(color);
}

void BottomMenu::setBackGroundColor(sf::Color color) {
    bar.setTextColor(color);
}

void BottomMenu::setFont(States::fonts font, States::fontStyle style) {
    fontList.setFont(font, style);
}

void BottomMenu::reset() {
    sliders[0].setCurrent(0);
    sliders[1].setCurrent(0);
    sliders[2].setCurrent(255);
    sliders[3].setCurrent(70);
    sliders[4].setCurrent(55);
    sliders[5].setCurrent(255);
    sliders[6].setCurrent(255);
    sliders[7].setCurrent(500);
    sliders[8].setCurrent(164);
    sliders[9].setCurrent(509);
    sliders[10].setCurrent(250);
    inputBox.setText("");
    bar.setTextColor(sf::Color::Red);
    bar.setBackgroundColor(sf::Color::Black);
    fontList.setFont(States::ARIAL, States::REGULAR);
}

void BottomMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(int i = 0; i < sliders.size(); i ++){
        window.draw(sliders.at(i));
    }
    window.draw(inputBox);
    window.draw(bar);
    window.draw(fontList);}

void BottomMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    inputBox.addEventHandler(window, event);
    bar.addEventHandler(window, event);
    fontList.addEventHandler(window, event);
    for(int i = 0; i < sliders.size(); i ++){
        sliders.at(i).addEventHandler(window, event);
    }


    if(States::isStatusSet(States::SAVE_PROJ)){
        std::ofstream file;
        std::string filename = filePrompt.run();
        if(filename != "NULL"){
            filename = "Project/" + filename + ".txt";
            file.open(filename);
            file << getLogoText() + "\n";
            for(int i = 0; i < sliders.size(); i++){
                file << std::to_string(sliders.at(i).getCurVal()) << " ";
            }
            sf::Color logoColor = getTextColor();
            sf::Color backColor = getBackGroundColor();
            file << std::to_string(logoColor.r) << " ";
            file << std::to_string(logoColor.g) << " ";
            file << std::to_string(logoColor.b) << " ";
            file << std::to_string(backColor.r) << " ";
            file << std::to_string(backColor.g) << " ";
            file << std::to_string(backColor.b) << " ";

            // font
            file << std::to_string(static_cast<int>(fontList.getFont())) << " ";
            file << std::to_string(static_cast<int>(fontList.getStyle()));
            file.close();
        }
        States::setStatus(States::SAVE_PROJ, false);
    }

    if(States::isStatusSet(States::OPEN_PROJ)){
        std::ifstream file;
        std::string filename = States::fileToOpen;
        filename = "Project/" + filename;
        file.open(filename);
        if(file.is_open()){
            std::string name;
            getline(file, name);
            inputBox.setText(name);
            int temp;
            for(int i = 0; i < sliders.size(); i++){
                file >> temp;
                sliders.at(i).setCurrent(temp);
            }
            int r,g,b;
            file >> r >> g >> b;
            bar.setTextColor(sf::Color(r,g,b));
            file >> r >> g >> b;
            bar.setBackgroundColor(sf::Color(r,g,b));

            // font
            int font, style;
            file >> font;
            file >> style;
            fontList.setFont(static_cast<States::fonts>(font), static_cast<States::fontStyle>(style));
            file.close();
        }

        States::setStatus(States::OPEN_PROJ, false);
    }
}

void BottomMenu::update() {
    inputBox.update();
    fontList.update();
}
