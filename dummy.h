#ifndef DUMMY_H
#define DUMMY_H

#include "enemy.h"

class Dummy :public Enemy
{
public:
    Dummy(sf::Texture *look_from_game);


    virtual void walk_animate();
    virtual void attack_animate(float &angle_from_trigger);

};

#endif // DUMMY_H
