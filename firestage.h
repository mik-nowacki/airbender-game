#ifndef FIRESTAGE_H
#define FIRESTAGE_H

#include "earthstage.h"
#include "worm.h"

class FireStage :public Game
{
public:
    FireStage();
    virtual void spawn_creatures();
    virtual void upload_waves();
};

#endif // FIRESTAGE_H
