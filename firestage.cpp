#include "firestage.h"

FireStage::FireStage()
{
    this->stage = FIRE;
    this->story->stage_complete = false;
    this->max_creatures=15;

}

void FireStage::spawn_creatures()
{
    if(creatures_counter<=max_creatures)
    {
        Worm *worm = new Worm(&enemy_tex[WORM],&abilities[FIREBALL],mapBoarder);
        this->enemies.push_back(worm);
        creatures_counter++;
    }
}
