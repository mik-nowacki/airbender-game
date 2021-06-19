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

    std::vector<std::vector<sf::Sprite>> tileMap;   // all map tiles in one place :)
    int fromX=0;
    int toX=0;
    int fromY=0;
    int toY=0;
    float gridSizef_ =100.f;

protected:
    void initalizeBackground(sf::Texture &back);
//    unsigned gridSizeu=static_cast<unsigned>(gridSizef);
    sf::Texture texture;
    int mapSize;
    sf::RectangleShape tileSelector;
    sf::RectangleShape grid;
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;
    sf::Sprite cur_back;

};

#endif // LANDSCAPE_H
