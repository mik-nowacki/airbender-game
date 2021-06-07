#include "projectile.h"

Projectile::Projectile()
{
}
void Projectile::launchProjectile(sf::Vector2f &shooter, sf::Vector2f &target)
{
    this->setPosition(shooter);
    this->aimDirection = target - shooter;
    this->aimDirNorm = aimDirection / float(sqrt(powf(aimDirection.x,2.f)+powf(aimDirection.y,2.f)));
    this->speedVector=aimDirNorm*maxSpeed;

    this->rotate(atan2f(aimDirNorm.y,aimDirNorm.x)*(180/3.141592653589793238463));

}

void Projectile::update_movement(float dt_)
{
        this->move(this->speedVector*dt_);
}
bool Projectile::is_hit(sf::RectangleShape &target)
{
    if(this->getGlobalBounds().intersects(target.getGlobalBounds()))
        return true;
    else
        return false;
}

void Projectile::make_tempest(sf::Texture *tex, short ability)
{
    this->texture=tex;
    this->setTexture(*texture);
    this->maxSpeed = 600.f;
    this->type = ability;

}
void Projectile::make_iceCone(sf::Texture *tex, short ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this->setScale(0.15,0.15);
    this->maxSpeed = 400;
    this->type = ability;

}

void Projectile::make_fireball(sf::Texture *tex, short ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this -> setTextureRect(sf::IntRect(70,86,110,54));
    this->maxSpeed = 500;
    this->type = ability;

}
void Projectile::make_boulder(sf::Texture *tex, short ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this->maxSpeed = 250;
    this->type = ability;
}

