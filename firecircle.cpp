#include "firecircle.h"

FireCircle::FireCircle(sf::Texture *tex, const short &ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this->type = ability;
    this->maxSpeed=0;
}

void FireCircle::launchProjectile(sf::Vector2f &shooter, sf::Vector2f &target)
{
    this->setOrigin(this->texture->getSize().x/2.f,this->texture->getSize().y/2.f);
    this->setPosition(shooter);
}

void FireCircle::update_movement(const float &dt_)
{
    scale*=1.01f;
    this->setScale(scale,scale);
}
