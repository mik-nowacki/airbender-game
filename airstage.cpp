#include "airstage.h"

AirStage::AirStage()
{
    this->stage=AIR;
    this->max_creatures=5;
}

void AirStage::spawn_creatures()
{
    if(creatures_counter<max_creatures)
    {
        std::shared_ptr dummy = std::make_shared<Dummy>(enemy_id,&enemy_tex[DUMMY],&abilities[FIREBALL],mapBoarder);
        this->enemies.push_back(dummy);
        creatures_counter++;
        enemy_id++;
    }
}

void AirStage::upload_waves()
{
    if (story->creaturesSlain()>=5)
        spawn_soldiers();
    if (story->soldiersKilled()>=5)
        max_soldiers=10;
    spawn_creatures();
}
