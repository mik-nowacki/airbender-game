#include "landscape.h"

Landscape::Landscape()
{

}

void Landscape::renderMap()
{
    fromX=avatar.view.getCenter().x / gridSizef -10;
    toX=avatar.view.getCenter().x / gridSizef+11;

    fromY=avatar.view.getCenter().y / gridSizef-6;
    toY=avatar.view.getCenter().y / gridSizef+7;

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

    if (!windTemple.loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/airKingdomGround.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
//    texture_grass.setRepeated(true);
//    sf::Sprite grass;
//    grass.setTexture(texture_grass);
//    grass.setTextureRect(sf::IntRect(0, 0, 800, 600));
    windTemple.setRepeated(true);

    tileMap.resize(mapSize,std::vector<sf::Sprite>());

    for (int x=0; x<mapSize;x++)
    {
        tileMap[x].resize(mapSize,sf::Sprite());
        for (int y=0; y<mapSize;y++)
        {
            tileMap[x][y].setTexture(windTemple);
//            tileMap[x][y].setTextureRect(sf::IntRect(0,0,100,100));
            tileMap[x][y].setScale(0.2,0.2);
//            tileMap[x][y].setFillColor(sf::Color::White);
//            tileMap[x][y].setOutlineThickness(1.f);
//            tileMap[x][y].setOutlineColor(sf::Color::Black);
            tileMap[x][y].setPosition(x*gridSizef,y*gridSizef);

        }
    }
}
