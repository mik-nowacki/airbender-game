#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "avatar.h"

class Landscape
{
public:
    Landscape(float gridSize);

    void updatePositions();                 //Updtaes all positions: view, mouse etc.
    void renderMap(Avatar &avatar_clone);   // draw tiles only in the VIEW
    void initializeMap();                   // initalize ENTIRE map

    std::vector<std::vector<sf::Sprite>> tileMap;   // all map tiles in one place :)
    int fromX=0;
    int toX=0;
    int fromY=0;
    int toY=0;
    float gridSizef_ =100.f;
private:
//    unsigned gridSizeu=static_cast<unsigned>(gridSizef);
    const int mapSize = 100;
    sf::Texture windTemple;

    sf::RectangleShape tileSelector;
    sf::RectangleShape grid;
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;

};

#endif // LANDSCAPE_H
