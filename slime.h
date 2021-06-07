#ifndef SLIME_H
#define SLIME_H

#include "soldier.h"

class Slime :public Enemy
{
public:
    Slime(sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder);
    virtual ~Slime();

    sf::Vector2u textureSize;

    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);
};

#endif // SLIME_H
