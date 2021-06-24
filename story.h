#ifndef STORY_H
#define STORY_H

#include <SFML/Graphics.hpp>

#include "landscape.h"
#include "avatar.h"

class Story
{
public:
    Story(std::vector<sf::Texture> *tex, sf::Texture *appa_game,std::vector<sf::Texture> *bend_tex);

    void set_stage(short &stage);
    void updateStory(const float &game_dt, sf::RenderTarget &game_window, Avatar &player);
    void updateQuests(Avatar &player,sf::RenderTarget &game_window);
    void capturing(const float &dt_, const sf::RectangleShape &player);
    bool stageComplete();  // if window can be closed
    void addDeadCreature();
    void addDeadSoldier();
    int creaturesSlain();
    int soldiersKilled();

private:
    bool is_captured = false;
    bool unlocked = false;
    int dead_creatures=0;
    int dead_soldiers=0;
    short current_stage;
    bool on_appa=false;

    sf::Sprite bender,text;
    std::vector<sf::Texture> benders;

    sf::Sprite altar;
    sf::CircleShape altar_hb;
    float capture_time=0;
    std::vector<sf::Texture> texture;

    sf::Sprite appa;
    sf::Texture appa_tex;

};

#endif // STORY_H
