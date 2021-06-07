#ifndef AVATAR_H
#define AVATAR_H

#include <cmath>

#include "entity.h"

class Avatar :public Entity
{
public:
    Avatar(sf::RectangleShape &game_boarder);

 // VARIABLES

    sf::View view;
    sf::Vector2f mousePosView;
    sf::Vector2f mousePos;
    sf::RectangleShape trigger_area;

    short animState;
    short chosen_element;

    std::vector<bool>permission = {false, false, false, false, false, false, false,false, false, false, false, false};

  // METHODS

    void steering(float dt_); // Avatar + Camera movement
    void shooting(float dt_);
    void animate(float dt_);
    void movement_animation();
    void get_textures(std::vector<sf::Texture> *mv_game, std::vector<sf::Texture> *at_game, std::vector<sf::Texture> *sk_game);
    void attack_animation();

private:
    float avatar_movement_speed=500.f;
    sf::Vector2f  start_pos={900.f,500.f};

 // MOVING VARS
    std::vector<sf::Texture> move_textures, attack_textures, skill_textures;
    std::vector<sf::Vector2u> walkSize, attackSize;
    unsigned idle_counter=0, up_counter=0, down_counter=0, left_counter=0, right_counter=0;

 // SHOOTING VARS
    bool shot = false;
    float angle;
    sf::Vector2f shooter_center;
    Projectile *projectile;

 // ABILITY VARS
    float element_swap=2;
    float on_cooldown = 10; //??? NEEDS CHANGE
    std::vector<float> ability_cooldown = {1,10,5}; //BASIC, PASSIVE, SUPER
    std::pair<bool,float> passive_timer; // duration 5s
    float armor;  // +75 HP TEMPORARLY
    float add_dmg=0; // +25 DMG
    std::pair<bool,float> heal = {false,0}; // HEALS 5 HP EVERY SECOND

 // ATTACK ANIM VARS
    float pause_time = 0.5;
    float attack_anim_timer = pause_time;
    unsigned at_counter = 0 ;

};

#endif // AVATAR_H
