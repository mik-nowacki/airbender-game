#ifndef FIRESTAGE_H
#define FIRESTAGE_H

#include "earthstage.h"
#include "worm.h"

class FireStage :public Game
{
public:
    FireStage();
    virtual void spawn_creatures();
};

#endif // FIRESTAGE_H
