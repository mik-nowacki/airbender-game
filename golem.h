#ifndef GOLEM_H
#define GOLEM_H

#include "enemy.h"

class Golem :public Enemy
{
public:
    Golem(sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder);
    virtual ~Golem();

protected:
    virtual void hit_box_position();
    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);
};

#endif // GOLEM_H
