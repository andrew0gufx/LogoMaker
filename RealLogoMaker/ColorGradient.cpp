//
// Created by 16177 on 2022/4/27.
//

#include "ColorGradient.h"
ColorGradient::ColorGradient(sf::Color color){
    gradients.setPrimitiveType(sf::Points);
    int height = 256;
    int width = 256;
    gradients.resize(height*width);      // color range 0-255
    background.setSize({256, 256});
    background.setFillColor(sf::Color::Black);
    setColor(color);
}

ColorGradient::ColorGradient()
        : ColorGradient(sf::Color::Blue){

}


void ColorGradient::setPosition(float x, float y){
    int height = gradients.getBounds().height+1;
    int width = gradients.getBounds().width+1;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            sf::Vertex& vertex = gradients[i*width + j];
            vertex.position = sf::Vector2f(x+j,y+i);
        }
    }
    background.setPosition(x, y);
}


sf::FloatRect ColorGradient::getGlobalBounds(){
    return gradients.getBounds();
}



// pos == mousePos
sf::Color ColorGradient::getColor(sf::Vector2i pos){
    int height = gradients.getBounds().height;
    int width = gradients.getBounds().width;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            sf::Vertex& vertex = gradients[i*width + j];
            if((int)vertex.position.x == pos.x && (int)vertex.position.y == pos.y){
                return vertex.color;
            }
        }
    }
    return none;
}


void ColorGradient::setColor(sf::Color color){
    int height = 256;
    int width = 256;
    int r = color.r, g = color.g, b = color.b;

    // find hsv
    int M,m;
    if(r == 255 && g == 255 && b == 255){
        M = 255;
        m = 255;
    }else if(r == 0 && g == 0 && b == 0){
        M = 0;
        m = 0;
    }else{
        M = 255;
        m = 0;
    }
    int c = M-m;
    double H;
    if(c == 0){
        H = 0;
    }else if(M == r){
        H = 60*((g-b)/c % 6);
    }else if(M == g){
        H = 60*((double)(b-r)/c + 2);
    }else{
        // M == b
        H = 60*((double)(r-g)/c + 4);
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            sf::Vertex& vertex = gradients[i*width + j];

            // find new hsv and convert back to rgb
            double V;
            double S;
            S = (i == 0)? 0:((double)j/255);
            V = (double)i/255;


            // change to rgb
            int h = H/60;
            double f = ((double)H/60 - h);
            double p = V*(1-S);
            double q = V*(1-S*f);
            double t = V*(1-S*(1-f));

            int newR, newG, newB;
            if(h == 0 || h == 6){
                newR = V*255;
                newG = t*255;
                newB = p*255;
            }else if(h == 1){
                newR = q*255;
                newG = V*255;
                newB = p*255;
            }else if(h == 2){
                newR = p*255;
                newG = V*255;
                newB = t*255;
            }else if(h == 3){
                newR = p*255;
                newG = q*255;
                newB = V*255;
            }else if(h == 4){
                newR = t*255;
                newG = p*255;
                newB = V*255;
            }else{
                // h == 5
                newR = V*255;
                newG = p*255;
                newB = q*255;
            }
            if(c == 0){
                newR = 255-j;
                newG = 255-j;
                newB = 255-j;
            }

            vertex.color = sf::Color(newR, newG, newB);

            vertex.position = sf::Vector2f(j,i);
        }
    }
}


void ColorGradient::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(background);
    window.draw(gradients);
}