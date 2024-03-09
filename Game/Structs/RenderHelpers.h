#ifndef RENDERHELPERS_H_INCLUDED
#define RENDERHELPERS_H_INCLUDED
#include "../../Structs/SDL_Block.h"
#include "../../Structs/SDL_Visual.h"
#include <SDL.h>
struct Static_Block{
    SDL_Block block;
    bool show;
};
struct Render_Surface{
    int id; //Entity ID
    SDL_Visual surface;
    bool show;
};
#endif // RENDERHELPERS_H_INCLUDED
