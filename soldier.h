#ifndef SOLDIER_H
#define SOLDIER_H

#include "enemy.h"

class Soldier :public Enemy
{
public:
    Soldier(sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder);
    virtual ~Soldier();

    sf::Vector2u textureSize;


    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);


};

#endif // SOLDIER_H
