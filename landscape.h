#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "avatar.h"

class Landscape
{
public:
    Landscape();

    void renderMap();
    void initializeMap();

    Avatar avatar;

    std::vector<std::vector<sf::Sprite>> tileMap;
    int fromX=0;
    int toX=0;
    int fromY=0;
    int toY=0;
private:
    float gridSizef =100.f;
    unsigned gridSizeu=static_cast<unsigned>(gridSizef);
    const int mapSize = 100;
    sf::Texture windTemple;

    sf::RectangleShape tileSelector;
    sf::RectangleShape grid;

};

#endif // LANDSCAPE_H
