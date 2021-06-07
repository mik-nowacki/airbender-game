#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Menu
{
public:
    Menu();
    void openMenu();

private:
    sf::RenderWindow *menu_window;
    sf::Sprite *button;
    sf::Sprite new_game;
    sf::Sprite options;
    sf::Texture menu_texture;
};

#endif // MENU_H
