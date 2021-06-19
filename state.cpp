#include "state.h"

State::State()
{
}

void State::initialie_program()
{
    menu = std::make_unique<Menu>();
    menu->openMenu();

    do{
        stage = std::make_unique<AirStage>();
        stage->run();
    }while(stage->getAvatarHP()<=0);

    do{
        stage = std::make_unique<WaterStage>();
        stage->run();
    }while(stage->getAvatarHP()<=0);

    do{
        stage = std::make_unique<EarthStage>();
        stage->run();
    }while(stage->getAvatarHP()<=0);

    do{
        stage = std::make_unique<FireStage>();
        stage->run();
    }while(stage->getAvatarHP()<=0);

    do{
        stage = std::make_unique<BossStage>();
        stage->run();
    }while(stage->getAvatarHP()<=0);
}
