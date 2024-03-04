#include "SDLWorld.h"
#include "InitError.h"
#include "../Mapping/SDLMapping.h"
SDLWorld::SDLWorld( Data_Game gameData, Uint32 flags )
{
    if ( SDL_Init( flags ) != 0 )
        throw InitError();

    if ( SDL_CreateWindowAndRenderer( gameData.WindowWidth, gameData.WindowHeight, SDL_WINDOW_SHOWN,
                                      &m_window, &m_renderer ) != 0 )
        throw InitError();
}

SDLWorld::~SDLWorld()
{
    delete[] tiles;
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
}

void SDLWorld::draw()
{
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );

    for(long unsigned int i = 0; i < 100; i++){

        SDL_SetRenderDrawColor( m_renderer, (int)tiles[i].color.a, (int)tiles[i].color.b, (int)tiles[i].color.c, 255);
        SDL_Rect bar = SDLMapping().ToSDLRect(tiles[i].rect);
        SDL_RenderFillRect( m_renderer, &bar);
        SDL_RenderPresent( m_renderer );
        SDL_Delay( 10 );
    }
    SDL_Delay( 100000 );
}

SDL_Block SDLWorld::GetBlock(TileProperties tile)
{
    SDL_Block block;
    block.color = tile.color;
    block.rect.properties.Size.a = 10;
    block.rect.properties.Size.b = 10;
    block.rect.properties.Location = tile.Location;
    return block;
}

void SDLWorld::load(Tile tiles[]){
    //int NumberOfTiles = sizeof(this->tiles);
    this->tiles = new SDL_Block[100];
    for(int i = 0; i < 100; i++){
        this->tiles[i] = GetBlock(tiles[i].GetProperties());
    }
}
