#ifndef BOSS_H
#define BOSS_H

#include "worm.h"

class Boss :public Enemy
{
public:
    Boss(int &arg_id, sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder);
    virtual ~Boss();
private:
    virtual void hit_box_position();
    virtual void untrigger();
    virtual void root();
    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);
};

#endif // BOSS_H
