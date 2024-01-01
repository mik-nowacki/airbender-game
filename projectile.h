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
    virtual ~Projectile();

    virtual void launchProjectile(sf::Vector2f &shooter, sf::Vector2f &target);
    virtual void update_movement(const float &dt_);
    bool canErase();

// make abilites
    void make_tempest(sf::Texture* tex, const short &ability);
    void make_iceCone(sf::Texture* tex, const short &ability);
    void make_stun(sf::Texture* tex, const short &ability);
    void make_fireball(sf::Texture* tex, const short &ability);
    void make_rock(sf::Texture* tex, const short &ability);
    void make_boulder(sf::Texture* tex, const short &ability);

    short Type();
    void deal(const int arg_id);
    bool id_match(const int arg_id);

protected:
    sf::Vector2f aimDirection;
    sf::Vector2f aimDirNorm;
    sf::Vector2f speedVector;
    sf::Texture *texture;
    short type;
    std::vector<int> id;
    float maxSpeed;
};

#endif // PROJECTILE_H
