#ifndef ENEMY_H
#define ENEMY_H

#include <cmath>

#include "entity.h"

enum EFFECT {SLOW,ROOT,IGNITE};

class Enemy :public Entity
{
public:
    Enemy(sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder);
    virtual ~Enemy();

    void AI(const float &dt_,const sf::RectangleShape &avatar_target, sf::RenderTarget &win);
    short enemy_type;
    void untrigger();
    void root();

protected:

    void AI_movement(const float &dt_);
    void trigger_AI(const sf::RectangleShape &trigger_box);
    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);
    virtual void hit_box_position();
    virtual void updateGUI(sf::RenderTarget &win);

    short attack_state;

    float movementSpeed = 50.f;
    float before_slow;
    short move_dir;
    std::unique_ptr<Projectile> skill;
    sf::Texture *look;
    sf::Texture *skill_look;
    sf::Sprite ability;
    sf::Vector2f targetPosition;
    sf::Vector2f shooter_center;

    sf::RectangleShape bar;
    sf::RectangleShape bar_back;

    bool if_triggered = false;
    float pause_time=1.5;
    float shot_interval;
};

#endif // ENEMY_H
