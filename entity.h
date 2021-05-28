#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
public:
    Entity();
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Text text;

};

#endif // ENTITY_H
