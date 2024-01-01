#include "waterstage.h"

WaterStage::WaterStage()
{
    this->stage = WATER;
    this->max_creatures=5;
    this->max_soldiers = 9;

}

void WaterStage::spawn_creatures()
{

    if(creatures_counter<max_creatures)
    {
       std::shared_ptr slime = std::make_shared<Slime>(enemy_id,&enemy_tex[SLIME],&abilities[ICECONE],mapBoarder);
        this->enemies.push_back(slime);
        creatures_counter++;
        enemy_id++;
    }
}

void WaterStage::upload_waves()
{
    if (story->creaturesSlain()==5)
        max_creatures = 10;
    else if (story->creaturesSlain()==10)
        max_creatures = 20;
    else if (story->creaturesSlain()>=15)
        spawn_soldiers();
    if (story->soldiersKilled()>=5)
        max_soldiers=10;
    spawn_creatures();
}
