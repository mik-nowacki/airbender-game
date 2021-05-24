#include "avatar.h"

Avatar::Avatar(float x, float y,float width, float height)
{
    rectangle.setPosition(x,y);
    rectangle.setSize(sf::Vector2f(width,height));
    rectangle.setFillColor(sf::Color::Cyan);
}

void Avatar::steering()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        rectangle.move(0,-5.f);
        view.move(0,-5.f);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        rectangle.move(0,5.f);
        view.move(0,5.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        rectangle.move(-5.f,0);
        view.move(-5.f,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        rectangle.move(5.f,0);
        view.move(5.f,0);
    }
}
