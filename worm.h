#ifndef WORM_H
#define WORM_H

#include "enemy.h"


class Worm :public Enemy
{
public:
    Worm(sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder);
    virtual ~Worm();

    sf::Vector2u textureSize;


    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);
};

#endif // WORM_H