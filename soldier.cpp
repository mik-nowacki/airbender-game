#include "soldier.h"

Soldier::Soldier(sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder)
{
//    this->shape.setSize(sf::Vector2f(100.f,100.f));
//    this->shape.setFillColor(sf::Color::Red);
    this->setPosition(sf::Vector2f(rand()%1000,rand()%1000));
    this->map_edge = game_boarder;
    this->clock.restart();
    move_dir = rand()%5;

// transfering looks
    this->look=look_from_game;
    this->setScale(3.5f,3.5f);
    this->setTexture(*look);

    textureSize = this->look->getSize();
    textureSize.x /=8;
    this->setTextureRect(sf::IntRect(textureSize.x*2, 0,textureSize.x,textureSize.y));

    this->skill_look=skill_look_from_game;
    this->ability.setTexture(*skill_look);

    this->enemy_type = SOLDIER;

    this->HP=100;
    this->if_triggered =false;
    this->shoot_timer=240;
}

Soldier::~Soldier()
{

}

void Soldier::walk_animate()
{
    switch(this->move_dir)
    {
        case IDLE: this->setTextureRect(sf::IntRect(textureSize.x*2, 0,textureSize.x,textureSize.y)); break;
        case MOVING_UP: this->setTextureRect(sf::IntRect(textureSize.x*3, 0,textureSize.x,textureSize.y)); break;
        case MOVING_DOWN: this->setTextureRect(sf::IntRect(textureSize.x*2, 0,textureSize.x,textureSize.y)); break;
        case MOVING_LEFT: this->setTextureRect(sf::IntRect(textureSize.x*0, 0,textureSize.x,textureSize.y)); break;
        case MOVING_RIGHT: this->setTextureRect(sf::IntRect(textureSize.x*1, 0,textureSize.x,textureSize.y)); break;
    }
}

void Soldier::attack_animate(float &angle_from_trigger)
{

    if (angle_from_trigger>-45 && angle_from_trigger<= 45)
        this->setTextureRect(sf::IntRect(textureSize.x*5, 0,textureSize.x,textureSize.y)); //RIGHT
    if (angle_from_trigger>-135 && angle_from_trigger<= -45)
        this->setTextureRect(sf::IntRect(textureSize.x*7, 0,textureSize.x,textureSize.y)); //UP
    if (angle_from_trigger> 45 && angle_from_trigger<= 135)
        this->setTextureRect(sf::IntRect(textureSize.x*6, 0,textureSize.x,textureSize.y)); // DOWN
    if (angle_from_trigger>135 || angle_from_trigger<=-135 )
        this->setTextureRect(sf::IntRect(textureSize.x*4, 0,textureSize.x,textureSize.y)); // LEFT
}
