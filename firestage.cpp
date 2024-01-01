#include "firestage.h"

FireStage::FireStage()
{
    this->stage = FIRE;
    this->max_creatures=5;

}

void FireStage::spawn_creatures()
{
    if(creatures_counter<max_creatures)
    {
        std::shared_ptr worm = std::make_shared<Worm>(enemy_id,&enemy_tex[WORM],&abilities[FIREBALL],mapBoarder);
        this->enemies.push_back(worm);
        creatures_counter++;
        enemy_id++;
    }
}

void FireStage::upload_waves()
{
    if (story->creaturesSlain()==5)
        max_creatures = 10;
    else if (story->creaturesSlain()==10)
        max_creatures = 15;
    else if (story->creaturesSlain()>=15)
        spawn_soldiers();
    if (story->soldiersKilled()>=5)
        max_soldiers=10;
    spawn_creatures();
}
