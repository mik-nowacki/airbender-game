#include "bossstage.h"

BossStage::BossStage()
{
    this->stage=BOSS;
    this->max_creatures=0;
    this->max_soldiers=9;
}

void BossStage::spawn_creatures()
{
    if(creatures_counter<=max_creatures)
    {
        std::shared_ptr boss = std::make_shared<Boss>(enemy_id,&enemy_tex[FIRE_LORD],&abilities[FIREBALL],mapBoarder);
        this->enemies.push_back(boss);
        creatures_counter++;
        enemy_id++;
    }
}
void BossStage::upload_waves()
{
    spawn_creatures();
    spawn_soldiers();
}
