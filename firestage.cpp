#include "firestage.h"

FireStage::FireStage()
{
    this->stage = FIRE;
    this->story->stage_complete = false;
    this->max_creatures=5;

}

void FireStage::spawn_creatures()
{
    if(creatures_counter<max_creatures)
    {
        std::shared_ptr worm = std::make_shared<Worm>(&enemy_tex[WORM],&abilities[FIREBALL],mapBoarder);
        this->enemies.push_back(worm);
        creatures_counter++;
    }
}

void FireStage::upload_waves()
{
    if (story->dead_creatures==5)
        max_creatures = 10;
    else if (story->dead_creatures==10)
        max_creatures = 15;
    else if (story->dead_creatures>=15)
        spawn_soldiers();
    if (story->dead_soldiers>=5)
        max_soldiers=10;
    spawn_creatures();
}
