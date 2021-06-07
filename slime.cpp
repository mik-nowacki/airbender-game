#include "slime.h"

Slime::Slime(sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder)
{
        this->setPosition(sf::Vector2f(rand()%1800,rand()%1800));
        this->map_edge = game_boarder;
        this->clock.restart();
        move_dir = rand()%5;

    // transfering looks
        this->look=look_from_game;
        this->setScale(3.f,3.f);
        this->setTexture(*look);

        textureSize = this->look->getSize();
        textureSize.x /=6;
        this->setTextureRect(sf::IntRect(textureSize.x*0, 0,textureSize.x,textureSize.y));

        this->skill_look=skill_look_from_game;
        this->ability.setTexture(*skill_look);

        this->enemy_type = SLIME;

        this->HP=50;
        this->movementSpeed = 35.f;
        this->if_triggered =false;
        this->shoot_timer=500;
}

Slime::~Slime()
{

}

void Slime::attack_animate(float &angle_from_trigger)
{
    this->setTextureRect(sf::IntRect(textureSize.x*5, 0,textureSize.x,textureSize.y));
}

void Slime::walk_animate()
{
    switch(this->move_dir)
    {
        case IDLE: this->setTextureRect(sf::IntRect(textureSize.x*0, 0,textureSize.x,textureSize.y)); break;
        case MOVING_UP: this->setTextureRect(sf::IntRect(textureSize.x*2, 0,textureSize.x,textureSize.y)); break;
        case MOVING_DOWN: this->setTextureRect(sf::IntRect(textureSize.x*4, 0,textureSize.x,textureSize.y)); break;
        case MOVING_LEFT: this->setTextureRect(sf::IntRect(textureSize.x*3, 0,textureSize.x,textureSize.y)); break;
        case MOVING_RIGHT: this->setTextureRect(sf::IntRect(textureSize.x*1, 0,textureSize.x,textureSize.y)); break;
    }

}
