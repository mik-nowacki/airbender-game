#ifndef AVATAR_H
#define AVATAR_H

#include "entity.h"

class Avatar :public Entity
{
public:
    Avatar(float x = 100.f, float y = 100.f,float width = 100.f, float height = 100.f);

    sf::RectangleShape rectangle;
    sf::View view;
    void steering();
};

#endif // AVATAR_H
