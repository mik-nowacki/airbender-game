#include "landscape.h"

Landscape::Landscape(float arg_gridSize)
{
    this->gridSizef_=arg_gridSize;
}

void Landscape::updatePositions()
{

}

void Landscape::renderMap(Avatar &avatar_clone)
{
    fromX=avatar_clone.view.getCenter().x / gridSizef_ -10;
    toX=avatar_clone.view.getCenter().x / gridSizef_+11;

    fromY=avatar_clone.view.getCenter().y / gridSizef_-6;
    toY=avatar_clone.view.getCenter().y / gridSizef_+7;

    if(fromX<0)
        fromX=0;
    else if(fromX>=mapSize)
        fromX=mapSize-1;

    if(fromY<0)
        fromY=0;
    else if(fromY>=mapSize)
        fromY=mapSize-1;

    if(toX<0)
        toX=0;
    else if(toX>=mapSize)
        toX=mapSize-1;

    if(toY<0)
        toY=0;
    else if(toY>=mapSize)
        toY=mapSize-1;
}

void Landscape::initializeMap()
{

    if (!windTemple.loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/waterKingdom.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    windTemple.setRepeated(true);
    tileMap.resize(mapSize,std::vector<sf::Sprite>());

    for (int x=0; x<mapSize;x++)
    {
        tileMap[x].resize(mapSize,sf::Sprite());
        for (int y=0; y<mapSize;y++)
        {
            tileMap[x][y].setTexture(windTemple);
//            tileMap[x][y].setTextureRect(sf::IntRect(0,0,100,100));
            tileMap[x][y].setScale(1.2,1.2);
//            tileMap[x][y].setFillColor(sf::Color::White);
//            tileMap[x][y].setOutlineThickness(1.f);
//            tileMap[x][y].setOutlineColor(sf::Color::Black);
            tileMap[x][y].setPosition(x*gridSizef_,y*gridSizef_);

        }
    }
}
