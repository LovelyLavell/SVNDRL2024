#ifndef RENDERSDL_H_INCLUDED
#define RENDERSDL_H_INCLUDED
#include "Structs/RenderHelpers.h"
#include "../Generated/SDL.h"
#include "Tile.h"
#include "Structs/TileProperties.h"
#include "Structs/WorldData.h"
#include "UI/SDLUI.h"
/*
*   This is the main SDL code, this will be used as a tool instead of having stuff placed inside of it
*/
class RenderSDL : public SDL
{
    TTF_Font * font;
    bool running;
    //Tiles will always be drawn first below everything.
    //Everything must be on a tile
    Static_Block * StaticTiles;

    Render_Surface * DynamicSurfaces;
    //Yeah I am not gonna have that much shit out but hey, you never know
    long unsigned int TileCount;
    long unsigned int EntityCount;
    int initialEntities;
    SDL_Block GetBlock(TileProperties tile, Vec3 Scale);
public:
    RenderSDL();
    RenderSDL( Data_Game gameData, Uint32 flags = 0 );
    void load(SDLUI * UI, int UICount);
    void load(WorldData data, Data_Game gameData) override;
    void Update();
    ~RenderSDL() override;
    void draw() override;
    TTF_Font * GetFont(){return font;};
    void update(int i, Vec3 loc, bool show) override;
    SDL_Renderer * GetRender(){return m_renderer;}
    SDL_Visual info;
};
#endif // RENDERSDL_H_INCLUDED
