#include "bossstage.h"

BossStage::BossStage()
{
    this->stage=BOSS;
    this->story->stage_complete=false;
    this->max_creatures=0;
}

void BossStage::spawn_creatures()
{
    if(creatures_counter<=max_creatures)
    {
        std::shared_ptr boss = std::make_shared<Boss>(&enemy_tex[FIRE_LORD],&abilities[FIREBALL],mapBoarder);
        this->enemies.push_back(boss);
        creatures_counter++;
    }
}
void BossStage::upload_waves()
{
    spawn_creatures();
}
