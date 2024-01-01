#ifndef FIRECIRCLE_H
#define FIRECIRCLE_H

#include "projectile.h"

class FireCircle :public Projectile
{
public:
    FireCircle(sf::Texture *tex, const short &ability);

    virtual void update_movement(const float &dt_);
    virtual void launchProjectile(sf::Vector2f &shooter, sf::Vector2f &target);

private:
    float scale = 1;
};

#endif // FIRECIRCLE_H
