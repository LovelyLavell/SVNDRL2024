#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "../World.h"
/*
* Sparse region with islands to access inbetween. The terrestrial part of the section.
*/
class Test: public World
{
public:
    Test();
    void Generate() override;
    void Logic()override;
    void Display()override;
    ~Test()override;
};

#endif // TEST_H_INCLUDED
