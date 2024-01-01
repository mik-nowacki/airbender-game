#ifndef BOSSSTAGE_H
#define BOSSSTAGE_H

#include "firestage.h"
#include "boss.h"

class BossStage :public Game
{
public:
    BossStage();

private:
    virtual void spawn_creatures();
    virtual void upload_waves();
};

#endif // BOSSSTAGE_H
