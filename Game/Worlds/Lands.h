#ifndef LANDS_H_INCLUDED
#define LANDS_H_INCLUDED
#include "../World.h"
/*
* Sparse region with islands to access inbetween. The terrestrial part of the section.
*/
class Lands: public World
{

public:
    Lands();
    void Generate() override;
    void Logic()override;
    void Display()override;
    ~Lands()override;
};
#endif // LANDS_H_INCLUDED
