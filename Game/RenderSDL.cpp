#include "RenderSDL.h"
#include "../Generated/InitError.h"
#include "../Mapping/SDLMapping.h"
RenderSDL::RenderSDL( Data_Game gameData, Uint32 flags )
{
    if ( SDL_Init( flags ) != 0 )
        throw InitError();

    if ( SDL_CreateWindowAndRenderer( gameData.WindowWidth, gameData.WindowHeight, SDL_WINDOW_SHOWN,
                                      &m_window, &m_renderer ) != 0 )
        throw InitError();
    font = TTF_OpenFont (strcat(SDL_GetBasePath(), "/Courier_Prime.ttf"), 16);
    //Moved stuff from section into here to leave this as the test class

    SDL_SetWindowTitle(m_window, gameData.title.c_str());
}

RenderSDL::~RenderSDL()
{
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
}

void RenderSDL::draw()
{
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    for(long unsigned int i = 0; i < TileCount; i++)
        Blit(StaticTiles[i].block);

    for(long unsigned int i = 0; i < EntityCount + initialEntities; i++)
        if(DynamicSurfaces[i].show)Blit(DynamicSurfaces[i].surface);
    Blit(info);
    SDL_RenderPresent( m_renderer );
}

void RenderSDL::update(int i, Vec3 loc, bool show){
    DynamicSurfaces[i].surface.location.properties.Location = loc;
    DynamicSurfaces[i].show = show;
};

SDL_Block RenderSDL::GetBlock(TileProperties tile, Vec3 Scale)
{
    SDL_Block block;
    block.color = tile.color;
    block.rect.properties = tile.properties;
    return block;
}

void RenderSDL::load(WorldData data, Data_Game gameData){
    //int NumberOfTiles = sizeof(this->tiles);
    this->StaticTiles = new Static_Block[data.tileCount];
    TileCount = data.tileCount;
    EntityCount = data.EntityCount;
    for(int i = 0; i < data.tileCount; i++){
        this->StaticTiles[i] = Static_Block();
        this->StaticTiles[i].show = true;
        this->StaticTiles[i].block = GetBlock(data.Tiles[i].GetProperties(), Vec3(gameData.ScaleWidth, gameData.ScaleHeight, 0));
    }
    //These will ALWAYS be here
    initialEntities = 2;
    DynamicSurfaces = new Render_Surface[data.EntityCount + initialEntities];
    DynamicSurfaces[0].surface = SDL_Visual('@', Vec3(255, 0, 0), Vec3(), font, m_renderer);
    DynamicSurfaces[1].surface = SDL_Visual('#', Vec3(255, 0, 0), Vec3(), font, m_renderer);

    //Rest of the elements
    for(int i = 0; i < data.EntityCount; i++){
        DynamicSurfaces[i + initialEntities].surface = SDL_Visual(data.Entities[i]->GetSymbol(), Vec3(255, 0, 0), data.Entities[i]->GetLocation(), font, m_renderer);
    }
}
