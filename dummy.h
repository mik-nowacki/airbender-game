#ifndef DUMMY_H
#define DUMMY_H

#include "enemy.h"

class Dummy :public Enemy
{
public:
    Dummy(int &arg_id, sf::Texture *look_from_game,sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder);
    virtual ~Dummy();
private:
    virtual void hit_box_position();
};

#endif // DUMMY_H
