#ifndef WATERSTAGE_H
#define WATERSTAGE_H

#include "airstage.h"
#include "slime.h"

class WaterStage :public Game
{
public:
    WaterStage();
    virtual void spawn_creatures();
};

#endif // WATERSTAGE_H
