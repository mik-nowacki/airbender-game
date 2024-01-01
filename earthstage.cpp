#include "earthstage.h"

EarthStage::EarthStage()
{
    this->stage = EARTH;
    this->max_creatures= 2;
}

void EarthStage::spawn_creatures()
{
    if(creatures_counter<max_creatures)
    {
        std::shared_ptr golem = std::make_shared<Golem>(enemy_id,&enemy_tex[GOLEM],&abilities[BOULDER],mapBoarder);
        this->enemies.push_back(golem);
        creatures_counter++;
        enemy_id++;
    }
}

void EarthStage::upload_waves()
{

    if (story->creaturesSlain()==2)
        max_creatures = 5;
    else if (story->creaturesSlain()==5)
        max_creatures = 8;
    else if (story->creaturesSlain()>=7)
        spawn_soldiers();
    if (story->soldiersKilled()>=5)
        max_soldiers=10;
    spawn_creatures();
}
