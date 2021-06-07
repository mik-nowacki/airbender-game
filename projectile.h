#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <cmath>
#include <iostream>

class Projectile :public sf::Sprite
{
public:
    Projectile();

    sf::Vector2f aimDirection;
    sf::Vector2f aimDirNorm;
    sf::Vector2f speedVector;
    sf::Sprite sprite;
    sf::Texture *texture;
    short type;

    void launchProjectile(sf::Vector2f &shooter, sf::Vector2f &target);
    void update_movement(float dt_);
    bool is_hit(sf::RectangleShape &target);

// make abilites
    void make_tempest(sf::Texture* tex, short ability);
    void make_iceCone(sf::Texture* tex, short ability);
    void make_fireball(sf::Texture* tex, short ability);

    void make_boulder(sf::Texture* tex, short ability);

protected:
    sf::RectangleShape shape;
    float maxSpeed=100;
private:
};

#endif // PROJECTILE_H
