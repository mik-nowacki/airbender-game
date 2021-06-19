#include "airstage.h"

AirStage::AirStage()
{
    this->stage=AIR;
    this->story->stage_complete=false;
    this->max_creatures=5;
}

void AirStage::spawn_creatures()
{
    if(creatures_counter<max_creatures)
    {
        std::shared_ptr dummy = std::make_shared<Dummy>(&enemy_tex[DUMMY],&abilities[FIREBALL],mapBoarder);
        this->enemies.push_back(dummy);
        creatures_counter++;
    }
}

void AirStage::upload_waves()
{
    if (story->dead_creatures>=5)
        spawn_soldiers();
    if (story->dead_soldiers>=5)
        max_soldiers=10;
    spawn_creatures();
}
