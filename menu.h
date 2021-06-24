#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <memory>


class Menu
{
public:
    Menu();
    void openMenu();
    bool get_break();

private:
    std::unique_ptr<sf::RenderWindow> menu_window;
    sf::Sprite new_game;
    sf::Texture menu_texture;
    bool close_program=false;
};

#endif // MENU_H
