#include "enemy.h"

Enemy::Enemy()
{
//    this->shape.setSize(sf::Vector2f(100.f,120.f));
//    this->shape.setFillColor(sf::Color::Red);
    this->sprite.setPosition(sf::Vector2f(rand()%10000,rand()%10000));
    if (!fireNationSoldierTexture.loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/fireNationSoldier.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    this->sprite.setTexture(fireNationSoldierTexture);
    this->sprite.setTextureRect(sf::IntRect(10,10,135,190));
//    this->sprite.setScale(0.2,0.2);
}
