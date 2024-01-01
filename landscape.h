#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "avatar.h"
#include <memory>

class Landscape
{
public:
    Landscape();

    void drawMap(sf::RenderTarget &win, Avatar &avatar_clone);
    void renderMap(Avatar &avatar_clone);   // render tiles only in the VIEW
    void initializeMap(const int &mapSize_from_game,sf::Texture *front,sf::Texture &back);

private:
    void initalizeBackground(sf::Texture &back);

    std::vector<std::vector<sf::Sprite>> tileMap;   // all map tiles in one place :)
    int fromX=0;
    int toX=0;
    int fromY=0;
    int toY=0;
    float gridSizef_;
    sf::Texture texture;
    int mapSize;
    sf::Sprite cur_back;

};

#endif // LANDSCAPE_H
