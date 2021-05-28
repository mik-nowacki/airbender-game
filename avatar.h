#ifndef AVATAR_H
#define AVATAR_H

#include <cmath>

#include "projectile.h"
#include "entity.h"
#include "enemy.h"

enum ANIMATION_STATES {IDLE = 0, MOVING_UP, MOVING_DOWN, MOVING_LEFT, MOVING_RIGHT};

class Avatar :public Entity
{
public:
    Avatar(float x = 100.f, float y = 100.f,float width = 100.f, float height = 100.f);

 // VARIABLES

    std::vector<Projectile> shots;

    sf::View view; // View coordinates
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;

    sf::Vector2f playerCenter;
    sf::Vector2f mousePos;
    sf::Vector2f aimDirection;
    sf::Vector2f aimDirNorm;

    sf::Texture avatar_Sheet;
    sf::Clock animation_timer;

    std::vector<sf::IntRect> idle = {sf::IntRect(5,20,23,34),sf::IntRect(28,20,23,34),sf::IntRect(52,20,23,34),sf::IntRect(77,20,23,34),sf::IntRect(102,20,23,34),sf::IntRect(128,20,23,34),sf::IntRect(152,20,23,34),sf::IntRect(175,20,23,34)}; //8
    unsigned idle_counter=0;
    std::vector<sf::IntRect> walkUp = {sf::IntRect(20,548,26,32),sf::IntRect(46,548,26,32),sf::IntRect(72,548,26,32),sf::IntRect(98,548,26,32),sf::IntRect(124,548,26,32),sf::IntRect(150,548,26,32),sf::IntRect(176,548,26,32),
                                      sf::IntRect(202,548,26,32),sf::IntRect(228,548,26,32),sf::IntRect(254,548,26,32),sf::IntRect(280,548,26,32)}; //11
    unsigned up_counter=0;
    std::vector<sf::IntRect> walkDown = {sf::IntRect(19,439,21,32),sf::IntRect(40,439,21,32),sf::IntRect(61,439,21,32),sf::IntRect(82,439,21,32),sf::IntRect(103,439,21,32),sf::IntRect(124,439,21,32),
                                        sf::IntRect(145,439,21,32),sf::IntRect(166,439,21,32),sf::IntRect(187,439,21,32),sf::IntRect(208,439,21,32)}; //10
    unsigned down_counter=0;
    std::vector<sf::IntRect> walkLeft = {sf::IntRect(85,202,27,33),sf::IntRect(112,202,27,33),sf::IntRect(140,202,27,33),sf::IntRect(167,202,27,33)}; //4
    unsigned left_counter=0;
    std::vector<sf::IntRect> walkRight = {sf::IntRect(17,82,26,34),sf::IntRect(44,82,26,34),sf::IntRect(70,82,26,34),sf::IntRect(98,82,26,34)}; //4
    unsigned right_counter=0;

    float avatar_movement_speed=700.f;
    bool moving = false;
    short animState;

  // FUNCTIONS

    void steering(float dt_); // Avatar + Camera movement
    void setMousePositions();
    void shooting(Projectile &bullet, std::vector<Enemy> &enemies, float dt_);
    void updateMousePosition();
    void animate(float dt_);
    void idle_animation();

private:
//    void get_texture();
};

#endif // AVATAR_H
