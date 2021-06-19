#ifndef STATE_H
#define STATE_H

#include "bossstage.h"
#include "menu.h"

class State
{
public:
    State();
    void initialie_program();

private:
    std::unique_ptr<Menu> menu;
    std::unique_ptr<Game> stage;
};

#endif // STATE_H
