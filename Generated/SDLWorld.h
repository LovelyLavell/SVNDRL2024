#ifndef SDLWORLD_H_INCLUDED
#define SDLWORLD_H_INCLUDED
#include "SDL.h"
#include "../Structs/SDL_Block.h"
#include "../Superfluous/structs/TRect.h"
#include "../Structs/Vec3.h"
#include "../Structs/Set_Color.h"
#include "../Game/Structs/TileProperties.h"
#include "../Game/Tile.h"
class SDLWorld final : public SDL
{
    SDL_Block * tiles;
    SDL_Block GetBlock(TileProperties tile);
public:
    SDLWorld();
    SDLWorld( Data_Game gameData, Uint32 flags = 0 );
    void load(Tile tiles[]);
    ~SDLWorld() override;
    void draw() override;
};


#endif // SDLWORLD_H_INCLUDED
