#include "menu.h"

Menu::Menu()
{
    menu_window=new sf::RenderWindow(sf::VideoMode(930,630), "Avatar game!");
    this->menu_window->setFramerateLimit(144);

    if(!menu_texture.loadFromFile("F:/QtCreator/MyDocuments/Airbender_Game/Textures/screens.png"))
        throw "Could not load screens";
    this->new_game.setTexture(menu_texture);
    this->new_game.setTextureRect(sf::IntRect(500,170,235,160));
    this->new_game.setScale(4.f,4.f);
    this->options.setTexture(menu_texture);
    this->options.setScale(4.f,4.f);
    this->options.setTextureRect(sf::IntRect(253,336,235,160));

    this->button=&new_game;
}

void Menu::openMenu()
{

    while(this->menu_window->isOpen())
    {



        sf::Event event;
        while (menu_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                menu_window->close();
        }
        menu_window->clear();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            this->button=&new_game;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            this->button=&options;

        menu_window->draw(*button);

        menu_window->display();
    }

}
