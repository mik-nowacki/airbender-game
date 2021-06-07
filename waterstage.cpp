#include "waterstage.h"

WaterStage::WaterStage()
{
    this->stage = WATER;
    this->story->stage_complete = false;
    this->max_creatures=20;

}

void WaterStage::spawn_creatures()
{
    if(creatures_counter<=max_creatures)
    {
        Slime *slime = new Slime(&enemy_tex[SLIME],&abilities[ICECONE],mapBoarder);
        this->enemies.push_back(slime);
        creatures_counter++;
    }
}
