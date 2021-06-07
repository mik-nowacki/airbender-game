#include "dummy.h"

Dummy::Dummy(sf::Texture *look_from_game)
{
    this->setPosition(sf::Vector2f(rand()%1800,rand()%1800));
    this->look=look_from_game;
    this->setTexture(*look);
    this->setScale(0.7f,0.7f);

    this->enemy_type = DUMMY;

    this->HP=1;

    this->movementSpeed = 0;

}
void Dummy::walk_animate()
{

}

void Dummy::attack_animate(float &angle_from_trigger)
{

}
