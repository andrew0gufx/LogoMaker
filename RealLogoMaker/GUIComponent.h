//
// Created by 16177 on 2022/3/22.
//

#ifndef SFML_PROJECT_GUICOMPONENT_H
#define SFML_PROJECT_GUICOMPONENT_H
#include <SFML/Graphics.hpp>
#include "SnapshotInterface.h"
#include "EventHandler.h"
#include "States.h"

class GUIComponent: public sf::Drawable, public sf::Transformable, public SnapshotInterface,
                    public EventHandler, public States{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};

#endif //SFML_PROJECT_GUICOMPONENT_H
