#include "earthstage.h"

EarthStage::EarthStage()
{
    this->stage = EARTH;
    this->story->stage_complete = false;
    this->max_creatures= 2;
}

void EarthStage::spawn_creatures()
{
    if(creatures_counter<max_creatures)
    {
        std::shared_ptr golem = std::make_shared<Golem>(&enemy_tex[GOLEM],&abilities[BOULDER],mapBoarder);
        this->enemies.push_back(golem);
        creatures_counter++;
    }
}

void EarthStage::upload_waves()
{

    if (story->dead_creatures==2)
        max_creatures = 5;
    else if (story->dead_creatures==5)
        max_creatures = 8;
    else if (story->dead_creatures>=7)
        spawn_soldiers();
    if (story->dead_soldiers>=5)
        max_soldiers=10;
    spawn_creatures();
}
