#ifndef SOLDIER_H
#define SOLDIER_H

#include "enemy.h"

class Soldier :public Enemy
{
public:
    Soldier(int &arg_id, sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder);
    virtual ~Soldier();

private:
    virtual void hit_box_position();
    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);
};

#endif // SOLDIER_H
