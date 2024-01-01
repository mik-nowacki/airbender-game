#include "landscape.h"

Landscape::Landscape()
{
    this->gridSizef_=100.f;
}

void Landscape::renderMap(Avatar &avatar_clone)
{
    fromX=avatar_clone.getView().getCenter().x / gridSizef_ -10;
    toX=avatar_clone.getView().getCenter().x / gridSizef_+11;

    fromY=avatar_clone.getView().getCenter().y / gridSizef_-6;
    toY=avatar_clone.getView().getCenter().y / gridSizef_+7;

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

void Landscape::initalizeBackground(sf::Texture &back)
{
    back.setRepeated(true);
    cur_back.setTexture(back);
    cur_back.setScale(5,5);
    cur_back.setTextureRect(sf::IntRect(0,0,1000,1000));
    cur_back.setPosition(-1000,-1000);
}

void Landscape::initializeMap(const int &mapSize_from_game, sf::Texture *front, sf::Texture &back)
{
    initalizeBackground(back);
    this->mapSize = mapSize_from_game;
    tileMap.resize(mapSize,std::vector<sf::Sprite>());

    for (int x=0; x<mapSize;x++)
    {
        tileMap[x].resize(mapSize,sf::Sprite());
        for (int y=0; y<mapSize;y++)
        {
            tileMap[x][y].setTexture(*front);
            tileMap[x][y].setTextureRect(sf::IntRect(0,0,100,100));
            tileMap[x][y].setPosition(x*gridSizef_,y*gridSizef_);
        }
    }

}

void Landscape::drawMap(sf::RenderTarget &win, Avatar &avatar_clone)
{
    win.draw(cur_back);
    renderMap(avatar_clone);
    for (int x=fromX;x<toX;x++)
    {
        for (int y=fromY; y<toY;y++)
        {
            win.draw(tileMap[x][y]);
        }
    }

}
