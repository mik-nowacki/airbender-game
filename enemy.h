#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy :public Entity
{
public:
    Enemy();

private:
    sf::Texture fireNationSoldierTexture;

};

#endif // ENEMY_H
