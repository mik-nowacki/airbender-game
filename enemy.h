#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>

#include "entity.h"

class Enemy :public Entity
{
public:
    Enemy();
    virtual ~Enemy();

    void AI(const float &dt_,sf::RectangleShape &avatar_target);
    short enemy_type;

protected:

    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);

    short attack_state;

    float movementSpeed = 50.f;
    short move_dir;
    Projectile *skill;
    sf::Texture *look;
    sf::Texture *skill_look;
    sf::Sprite ability;
    sf::Vector2f targetPosition;
     sf::Vector2f shooter_center;

    void trigger_AI(sf::RectangleShape &trigger_box);
    bool if_triggered = false;
    float pause_time=1.5;
};

#endif // ENEMY_H
