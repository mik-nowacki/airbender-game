#include "mechanics.h"

Mechanics::Mechanics()
{

}

//void Mechanics::steering()
//{
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//    {
//        rectangle.move(0,-10.f);
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//    {
//        rectangle.move(0,10.f);
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//    {
//        rectangle.move(-10.f,0);
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//    {
//        rectangle.move(10.f,0);
//    }
//}
//void Mechanics::shooting()
//{
//    playerCenter = sf::Vector2f(rectangle.getPosition().x+(0.5*rectangle.getGlobalBounds().width),rectangle.getPosition().y+0.5*rectangle.getGlobalBounds().height);
//    mousePos = sf::Vector2f(sf::Mouse::getPosition(*window));
//    aimDirection = mousePos-playerCenter;
//    aimDirNorm = aimDirection / sqrt(powf(aimDirection.x,2)+powf(aimDirection.y,2));

//    std::cout<<aimDirNorm.x<<" "<<aimDirNorm.y<<std::endl;

//}
