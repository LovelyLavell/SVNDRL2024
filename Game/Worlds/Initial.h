#ifndef INITIAL_H_INCLUDED
#define INITIAL_H_INCLUDED
#include "../World.h"
//The start area before the game begins
class Initial: public World
{

public:
    Initial();
    void Generate() override;
    void Logic()override;
    void Display()override;
    ~Initial()override;
};

#endif // INITIAL_H_INCLUDED
