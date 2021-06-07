#ifndef STORY_H
#define STORY_H

#include <SFML/Graphics.hpp>

#include "landscape.h"

class Story
{
public:
    Story(std::vector<sf::Texture> *tex, sf::Texture *appa_game,std::vector<sf::Texture> *land_tex);

//    std::vector<bool> is_captured;

    void capturing(const float &dt_, sf::RectangleShape &player);
    void updateStory(const float &game_dt, sf::RenderTarget &game_window, sf::RectangleShape &game_player);

    int change_landscape = 0;

    unsigned dead_soldiers;

    bool is_captured = false;
    bool unlocked = true;
    bool stage_complete;

    sf::Sprite altar;
    sf::CircleShape altar_hb;

    void updateQuests();

private:
    std::vector<sf::Texture> new_kingdom;
    sf::Sprite appa;
    sf::Texture appa_tex;

    float capture_time=0;
    std::vector<sf::Texture> texture;


};

#endif // STORY_H
