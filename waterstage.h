#ifndef WATERSTAGE_H
#define WATERSTAGE_H

#include "airstage.h"
#include "slime.h"

class WaterStage :public Game
{
public:
    WaterStage();

private:
    virtual void spawn_creatures();
    virtual void upload_waves();
};

#endif // WATERSTAGE_H
