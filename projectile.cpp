#include "projectile.h"

Projectile::Projectile(float radius) : speedVector(0.f,0.f), maxSpeed(15.f)
{
      this->shape.setFillColor(sf::Color::Magenta);
      this->shape.setRadius(radius);
}

//void Projectile::shooting(Projectile &bullet, std::vector<sf::RectangleShape> &enemies)
//{
//    playerCenter = sf::Vector2f(landscape.avatar.rectangle.getPosition().x+(0.5*landscape.avatar.rectangle.getGlobalBounds().width),landscape.avatar.rectangle.getPosition().y+0.5*landscape.avatar.rectangle.getGlobalBounds().height);
//    mousePos = sf::Vector2f(mousePosView);
//    aimDirection = mousePos-playerCenter;
//    aimDirNorm = aimDirection / sqrt(powf(aimDirection.x,2)+powf(aimDirection.y,2));


//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//    {
//        bullet.shape.setPosition(playerCenter);
//        bullet.speedVector=aimDirNorm*bullet.maxSpeed;

//        shots.emplace_back(bullet);
//    }
//    for(size_t i =0; i<shots.size(); i++)
//    {
//        shots[i].shape.move(shots[i].speedVector);
//    }
//    for(size_t i =0; i<shots.size();i++)
//    {
//        for(size_t k =0; k<enemies.size();k++)
//        if(shots[i].shape.getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
//        {
//            shots.erase(shots.begin()+i);
//            enemies.erase(enemies.begin()+k);

//        }
//    }
//}
