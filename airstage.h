#ifndef AIRSTAGE_H
#define AIRSTAGE_H

#include "game.h"
#include "dummy.h"

class AirStage :public Game
{
public:
    AirStage();

private:
    virtual void spawn_creatures();
    virtual void upload_waves();

};

#endif // AIRSTAGE_H
