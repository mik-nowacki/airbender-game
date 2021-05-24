#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>

#include "entity.h"
#include "projectile.h"
#include "landscape.h"
#include "enemy.h"

class Game
{
//    Avatar avatar;
    Landscape landscape;
    std::vector<Enemy> enemies;

    sf::RenderWindow *window;

    std::vector<Projectile> shots;

    sf::Vector2f playerCenter;
    sf::Vector2f mousePos;
    sf::Vector2f aimDirection;
    sf::Vector2f aimDirNorm;

    sf::Clock clock;
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;

    float gridSizef=100.f;

public:
    Game();
    void run();
//    void shooting(Projectile *bullet, std::vector<sf::RectangleShape> &enemies);
    void shooting(Projectile &bullet, std::vector<Enemy> &enemies);

};

#endif // GAME_H
