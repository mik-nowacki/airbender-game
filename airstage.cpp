#include "airstage.h"

AirStage::AirStage()
{
    this->stage=AIR;
    this->story->stage_complete=false;
    this->max_creatures=10;
}

void AirStage::spawn_creatures()
{
//    if(creatures_counter<=max_creatures)
//    {
//        Dummy *dummy = new Dummy(&enemy_tex[DUMMY]);
//        this->enemies.push_back(dummy);
//        creatures_counter++;
//    }
}
