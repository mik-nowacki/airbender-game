#ifndef MECHANICS_H
#define MECHANICS_H

#include "game.h"

class Mechanics
{
public:
    Mechanics();

    sf::RectangleShape rectangle;
    sf::RectangleShape enemy;

    sf::Vector2f playerCenter;
    sf::Vector2f mousePos;
    sf::Vector2f aimDirection;
    sf::Vector2f aimDirNorm;

    void steering();
    void shooting();

};

#endif // MECHANICS_H
