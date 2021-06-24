#include "entity.h"

Entity::Entity()
{
    this->hit_box.setFillColor(sf::Color::Transparent);
    this->hit_box.setOutlineThickness(3.f);
    this->hit_box.setOutlineColor(sf::Color::Green);
}
Entity::~Entity()
{

}

void Entity::drawShots(sf::RenderTarget &win)
{
    for (size_t i=0; i<shotsSize(); i++) // draw all avatar shots
    {
        win.draw(*shots[i]);
        if(!shots[i]->getGlobalBounds().intersects(map_edge.getGlobalBounds()))
            eraseShot(i);
    }
}

size_t Entity::shotsSize()
{
    return shots.size();
}

bool Entity::projectileScale(const int &k)
{
    return shots[k]->canErase();
}

const sf::Sprite Entity::bullet(const int &k)
{
    return *shots[k];
}

void Entity::eraseShot(const int &k)
{
    shots.erase(shots.begin()+k);
}

short Entity::shotType(const int &k)
{
    return shots[k]->Type();
}

bool Entity::matchID(const int &k, const int &ID)
{
    return shots[k]->id_match(ID);
}

void Entity::applyDMG(const int &k, const int &ID)
{
    shots[k]->deal(ID);
}

float Entity::get_angle(sf::Vector2f &shooter, sf::Vector2f &target)
{
    this->aimDirection = target - shooter;
    this->aimDirNorm = aimDirection / float(sqrt(powf(aimDirection.x,2.f)+powf(aimDirection.y,2.f)));

    return atan2f(aimDirNorm.y,aimDirNorm.x)*(180/3.141592653589793238463);
}
int Entity::getHP()
{
    return HP;
}
void Entity::reduceHP(const int &dmg)
{
    HP-=dmg;
}
void Entity::updateGUI(sf::RenderTarget &win)
{

}
bool Entity::hitBy(const sf::Sprite &hb)
{
    if (hit_box.getGlobalBounds().intersects(hb.getGlobalBounds()))
        return true;
    else
        return false;
}
