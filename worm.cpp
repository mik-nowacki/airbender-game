#include "worm.h"

Worm::Worm(sf::Texture *look_from_game, sf::Texture *skill_look_from_game,sf::RectangleShape &game_boarder) : Enemy(look_from_game,skill_look_from_game,game_boarder)
{
    this->setScale(3.f,3.f);

    textureSize = this->look->getSize();
    textureSize.x /=6;
    this->setTextureRect(sf::IntRect(textureSize.x*0, 0,textureSize.x,textureSize.y));

    hit_box.setSize(sf::Vector2f(130,75));

    this->enemy_type = WORM;

    this->HP=100;
    this->if_triggered =false;
    this->shoot_timer=240;

    bar.setSize(sf::Vector2f(HP,20));
    bar_back.setSize(sf::Vector2f(HP,20));
    bar.setOrigin(bar.getSize().x/2,bar.getSize().y/2);
    bar_back.setOrigin(bar.getSize().x/2,bar.getSize().y/2);
    bar.setFillColor(sf::Color::Red);
    bar_back.setFillColor(sf::Color(25,25,25,200));
}

Worm::~Worm(){}

void Worm::hit_box_position(){this->hit_box.setPosition(sf::Vector2f(this->getPosition().x+60,this->getPosition().y+40));}

void Worm::walk_animate()
{
    switch(this->move_dir)
    {
        case IDLE: this->setTextureRect(sf::IntRect(textureSize.x*0, 0,textureSize.x,textureSize.y)); break;
        case MOVING_UP: this->setTextureRect(sf::IntRect(textureSize.x*2, 0,textureSize.x,textureSize.y)); break;
        case MOVING_DOWN: this->setTextureRect(sf::IntRect(textureSize.x*3, 0,textureSize.x,textureSize.y)); break;
        case MOVING_LEFT: this->setTextureRect(sf::IntRect(textureSize.x*0, 0,textureSize.x,textureSize.y)); break;
        case MOVING_RIGHT: this->setTextureRect(sf::IntRect(textureSize.x*1, 0,textureSize.x,textureSize.y)); break;
    }
}

void Worm::attack_animate(float &angle_from_trigger)
{

    if (angle_from_trigger>-45 && angle_from_trigger<= 45)
        this->setTextureRect(sf::IntRect(textureSize.x*5, 0,textureSize.x,textureSize.y)); //RIGHT
    if (angle_from_trigger>-135 && angle_from_trigger<= -45)
        this->setTextureRect(sf::IntRect(textureSize.x*4, 0,textureSize.x,textureSize.y)); //UP
    if (angle_from_trigger> 45 && angle_from_trigger<= 135)
        this->setTextureRect(sf::IntRect(textureSize.x*5, 0,textureSize.x,textureSize.y)); // DOWN
    if (angle_from_trigger>135 || angle_from_trigger<=-135 )
        this->setTextureRect(sf::IntRect(textureSize.x*4, 0,textureSize.x,textureSize.y)); // LEFT
}
