#ifndef SDL_BLOCK_H_INCLUDED
#define SDL_BLOCK_H_INCLUDED
#include "../Superfluous/structs/TRect.h"
#include "Vec3.h"
struct SDL_Block{
    TRect rect;
    Vec3 color;
};

#endif // SDL_BLOCK_H_INCLUDED
