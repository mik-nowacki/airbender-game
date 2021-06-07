#ifndef AIRSTAGE_H
#define AIRSTAGE_H

#include "game.h"
#include "dummy.h"

class AirStage :public Game
{
public:
    AirStage();

    virtual void spawn_creatures();


};

#endif // AIRSTAGE_H
