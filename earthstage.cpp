#include "earthstage.h"

EarthStage::EarthStage()
{
    this->stage = EARTH;
    this->story->stage_complete = false;
    this->max_creatures= 8;
}

void EarthStage::spawn_creatures()
{
    if(creatures_counter<=max_creatures)
    {
        Golem *golem= new Golem(&enemy_tex[GOLEM],&abilities[BOULDER],mapBoarder);
        this->enemies.push_back(golem);
        creatures_counter++;
    }
}
