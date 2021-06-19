#ifndef EARTHSTAGE_H
#define EARTHSTAGE_H

#include "waterstage.h"
#include "golem.h"

class EarthStage :public Game
{
public:
    EarthStage();
    virtual void spawn_creatures();
    virtual void upload_waves();
};

#endif // EARTHSTAGE_H
