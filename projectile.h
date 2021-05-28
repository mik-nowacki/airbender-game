#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

class Projectile
{
public:
    Projectile(float radius = 5.f);

    sf::CircleShape shape;
    sf::Vector2f speedVector;
    float maxSpeed;

    void shooting(Projectile &bullet, std::vector<sf::RectangleShape> &enemies);

};

#endif // PROJECTILE_H
