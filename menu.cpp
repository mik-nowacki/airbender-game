#include "menu.h"

Menu::Menu()
{
    menu_window= std::make_unique<sf::RenderWindow>(sf::VideoMode(930,630), "Avatar game!");
    this->menu_window->setFramerateLimit(144);

    if(!menu_texture.loadFromFile("Textures/screens1.png"))
        throw "Could not load screens";
    this->new_game.setTexture(menu_texture);
    this->new_game.setTextureRect(sf::IntRect(500,170,235,160));
    this->new_game.setScale(4.f,4.f);
}

bool Menu::get_break()
{
    return close_program;
}

void Menu::openMenu()
{
    sf::RectangleShape button(sf::Vector2f(230.f,45.f));
    button.setPosition(350,495);
    while(this->menu_window->isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            menu_window->close();
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::Vector2f mousePos =sf::Vector2f(sf::Mouse::getPosition(*menu_window));
            sf::FloatRect bounds = button.getGlobalBounds();
            sf::Vector2f pos = button.getPosition();
            if (mousePos.x>=pos.x && mousePos.x<=pos.x+bounds.width &&
                    mousePos.y>=pos.y && mousePos.y<=pos.y+bounds.height)
                menu_window->close();
        }


        sf::Event event;
        while (menu_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                close_program=true;
                menu_window->close();
            }
        }
        menu_window->clear();

        menu_window->draw(new_game);

        menu_window->display();
    }

}
