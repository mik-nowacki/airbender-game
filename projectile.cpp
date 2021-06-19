#include "projectile.h"

Projectile::Projectile(){}
Projectile::~Projectile(){}
void Projectile::deal(const int arg_id)
{
    id.emplace_back(arg_id);
}
bool Projectile::id_match(const int arg_id)
{
    bool applied = false;
    for (auto &n : id)
    {
        if (n==arg_id)
            applied = true;
    }
    return applied;
}
void Projectile::launchProjectile(sf::Vector2f &shooter, sf::Vector2f &target)
{
    this->setPosition(shooter);
    this->aimDirection = target - shooter;
    this->aimDirNorm = aimDirection / float(sqrt(powf(aimDirection.x,2.f)+powf(aimDirection.y,2.f)));
    this->speedVector=aimDirNorm*maxSpeed;

    float angle = atan2f(aimDirNorm.y,aimDirNorm.x)*(180/3.141592653589793238463);
    this->rotate(angle);

    if ((angle>90 || angle<=-90 )&&type==5)
        this->setScale(1.f,-1.f); // LEFT

}
void Projectile::update_movement(float dt_)
{
        this->move(this->speedVector*dt_);
}

void Projectile::make_tempest(sf::Texture *tex, short ability)
{
    this->texture=tex;
    this->setTexture(*texture);
    this->setScale(2.7f,2.7f);
    this->maxSpeed = 600.f;
    this->type = ability;
}
void Projectile::make_iceCone(sf::Texture *tex, short ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this->setScale(0.2,0.2);
    this->maxSpeed = 400;
    this->type = ability;
}
void Projectile::make_rock(sf::Texture *tex, short ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this->setScale(0.3,0.3);
    this->maxSpeed = 500;
    this->type = ability;
}
void Projectile::make_fireball(sf::Texture *tex, short ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this -> setTextureRect(sf::IntRect(70,86,110,54));
    this->maxSpeed = 550;
    this->type = ability;
}
void Projectile::make_stun(sf::Texture *tex, short ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this->setScale(0.1,0.1);
    this->maxSpeed = 600;
    this->type = ability;
}
void Projectile::make_boulder(sf::Texture *tex, short ability)
{
    this->texture = tex;
    this->setTexture(*texture);
    this->setScale(0.8,0.8);
    this->maxSpeed = 250;
    this->type = ability;
}
