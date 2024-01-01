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
public:
    Game();
    virtual void run();
    int getAvatarHP();
protected:
    // METHODS
       void spawn_soldiers();
       virtual void spawn_creatures();
       virtual void upload_waves();
       void check_for_hits();
       void enemy_hits(Enemy &arg_enemies);
       void load_textures();

    std::unique_ptr<sf::RenderWindow> window;

 // TEXTURE VARIABLES
    sf::Texture appa_tex;
    std::vector<sf::Texture> enemy_tex;
    std::vector<sf::Texture> lands, backgroudns;
    std::vector<sf::Texture> benders, icons, buttons;
    std::vector<sf::Texture> avatar_walks, avatar_attacks;
    std::vector<sf::Texture> abilities;
    std::vector<sf::Texture> altar_stages;

 // KINGDOMS
    int mapSize=20;
    sf::RectangleShape mapBoarder;
    std::unique_ptr<Landscape> current_kingdom;

    std::unique_ptr<Story> story;

 // ENTITIES
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Enemy>> dead;
    std::unique_ptr<Avatar> avatar;

 // OTHER VARIABLES
    float gridSizef=100.f;

 // SPAWNING ENEMIES
    int enemy_id=1;
    int soldiers_counter = 0;
    int creatures_counter = 0;
    int max_soldiers = 5;
    int max_creatures;

    short stage;
};

#endif // GAME_H
