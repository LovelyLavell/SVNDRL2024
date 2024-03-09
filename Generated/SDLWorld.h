#ifndef SDLWORLD_H_INCLUDED
#define SDLWORLD_H_INCLUDED
#include "SDL.h"
#include "../Structs/SDL_Block.h"
#include "../Superfluous/structs/TRect.h"
#include "../Structs/Vec3.h"
#include "../Structs/Set_Color.h"
#include "../Game/Structs/TileProperties.h"
#include "../Game/Tile.h"
#include "../Structs/SDL_Text.h"
#include "../Structs/SDL_Visual.h"
//At this point this class will remain for testing
class SDLWorld final : public SDL
{
    int tileCount;
    SDL_Block * tiles;
    SDL_Visual * words;
    SDL_Block GetBlock(TileProperties tile, Vec3 Scale);
public:
    SDLWorld();
    SDLWorld( Data_Game gameData, Uint32 flags = 0 );
    void load(Tile tiles[], SDL_Text testWords[], Data_Game gameData);
    ~SDLWorld() override;
    void draw() override;
};
#endif // SDLWORLD_H_INCLUDED
