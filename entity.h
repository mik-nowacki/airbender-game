#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "firecircle.h"

enum ANIMATION_STATES {IDLE = 0, MOVING_UP, MOVING_DOWN, MOVING_LEFT, MOVING_RIGHT};
enum ELEMENTS {AIR= 0, WATER, EARTH, FIRE, BOSS};
enum ATTACK {RIGHT=0, UP, DOWN, LEFT};
enum SKILLS {TEMPEST =0, MS, CDR, ICECONE, HEAL, STUN, ROCK, ARMOR, BOULDER, FIREBALL, DMG, CIRCLE};
enum ENEMY_TYPE {DUMMY = 0 ,SLIME, GOLEM, WORM, SOLDIER, FIRE_LORD};

class Entity :public sf::Sprite
{
public:
    Entity();
    virtual ~Entity();

    int getHP();
    void reduceHP(const int &dmg);
    bool hitBy(const sf::Sprite &hb);
    const sf::Sprite bullet(const int &k);
    size_t shotsSize();
    void applyDMG(const int &k, const int &ID);
    short shotType(const int &k );
    bool matchID(const int &k, const int &ID);
    void eraseShot(const int &k);
    void drawShots(sf::RenderTarget &win);
    bool projectileScale(const int &k);

protected:
    sf::RectangleShape hit_box = sf::RectangleShape(sf::Vector2f(100.f,100.f));
    std::vector<std::shared_ptr<Projectile>> shots;
    virtual void updateGUI(sf::RenderTarget &win);
    int HP;

    float angle;
    float get_angle(sf::Vector2f &shooter, sf::Vector2f &target);

    sf::RectangleShape map_edge;
    short cant_move;
    float shoot_timer;

    sf::Vector2f aimDirection;
    sf::Vector2f aimDirNorm;
    sf::Vector2f playerCenter;

    sf::Vector2u textureSize;

    sf::Clock animation_timer;
    sf::Clock clock;
};

#endif // ENTITY_H
