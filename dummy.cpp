#include "dummy.h"

Dummy::Dummy(sf::Texture *look_from_game,sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder) : Enemy(look_from_game,skill_look_from_game,game_boarder)
{
    this->setScale(0.7f,0.7f);

    hit_box.setSize(sf::Vector2f(65,100));
    this->hit_box.setPosition(sf::Vector2f(this->getPosition().x,this->getPosition().y));

    this->enemy_type = DUMMY;

    this->HP=1;

    this->movementSpeed = 0;
}
Dummy::~Dummy()
{
}
void Dummy::hit_box_position(){this->hit_box.setPosition(sf::Vector2f(this->getPosition().x,this->getPosition().y));}
