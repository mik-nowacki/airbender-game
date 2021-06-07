#include "entity.h"

Entity::Entity()
{

}
//Entity::~Entity()
//{

//}

float Entity::get_angle(sf::Vector2f &shooter, sf::Vector2f &target)
{
    this->aimDirection = target - shooter;
    this->aimDirNorm = aimDirection / float(sqrt(powf(aimDirection.x,2.f)+powf(aimDirection.y,2.f)));

    return atan2f(aimDirNorm.y,aimDirNorm.x)*(180/3.141592653589793238463);
}
