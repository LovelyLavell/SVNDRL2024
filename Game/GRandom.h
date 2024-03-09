#ifndef GRANDOM_H_INCLUDED
#define GRANDOM_H_INCLUDED
#include <stdlib.h>
class GRandom
{
public:
    static void Seed(){
        srand(time(NULL));
    }
    static float GetRandom(int numMax, int numMin = 0){
        return rand() % numMax + numMin;
    }
};

#endif // GRANDOM_H_INCLUDED
