#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <math.h>

#include "story.h"
#include "soldier.h"

class Game
{
protected:

 // AIM POSITION
    sf::Vector2f playerCenter;
    sf::Vector2f mousePos;
    sf::Vector2f aimDirection;
    sf::Vector2f aimDirNorm;

 // MOUSE POSITIONS
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;

    sf::Clock clock;

 // TEXTURE VARIABLES

    sf::Texture avatar_sheet;
    sf::Texture appa_tex;
    sf::Texture default_enemy;
    std::vector<sf::Texture> enemy_tex;

    std::vector<sf::Texture> lands;
    std::vector<sf::Texture> avatar_walks;
    std::vector<sf::Texture> abilities;
    std::vector<sf::Texture> avatar_attacks;


    std::vector<sf::Texture> altar_stages;

 // KINGDOMS
    int mapSize=20;
    sf::RectangleShape mapBoarder;

    Landscape *current_kingdom;

//    std::vector <Environment*> environment;

 // ENTITIES
    std::vector<Enemy*> enemies;
    std::vector<Enemy*> dead;
    Avatar *avatar;

 // OTHER VARIABLES
    float gridSizef=100.f;
    float dt;

 // SPAWNING ENEMIES
//    if(spawn_clock.getElapsedTime().asSeconds()>=5&&creatures_counter<=max_creatures) CAN BE USEFUL!
    sf::Clock spawn_clock;
    int soldiers_counter = 0;
    int creatures_counter = 0;
    int max_soldiers = 30;
    int max_creatures;
    int dead_creatures = 0;

 // METHODS
    void spawn_environment();
    void spawn_soldiers();
    virtual void spawn_creatures();
    void check_for_hits();
    void dead_shots();
    void enemy_hits(Enemy &arg_enemies);
    void load_textures();

    short stage;

public:
    sf::RenderWindow *window;
    Story *story;
    Game();
    virtual void run();
};

#endif // GAME_H
