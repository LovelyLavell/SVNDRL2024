#include "SDLWorld.h"
#include "InitError.h"
#include "../Mapping/SDLMapping.h"
#include "../Game/Worlds/Test.h"
SDLWorld::SDLWorld( Data_Game gameData, Uint32 flags )
{
    if ( SDL_Init( flags ) != 0 )
        throw InitError();

    if ( SDL_CreateWindowAndRenderer( gameData.WindowWidth, gameData.WindowHeight, SDL_WINDOW_SHOWN,
                                      &m_window, &m_renderer ) != 0 )
        throw InitError();

    //Moved stuff from section into here to leave this as the test class
    World world = Test();
    world.Generate();
    Data_Message CopyMsg("System", "This is a test message", 0);
    TTF_Font * font = TTF_OpenFont (strcat(SDL_GetBasePath(), "/Courier_Prime.ttf"), 16);
    SDL_Text * testMessages = new SDL_Text[3]{
        SDL_Text(CopyMsg, font, Vec3(255, 0, 0), Set_Properties(Vec3(100, 100), Vec3(100, 50))),
        SDL_Text(CopyMsg, font, Vec3(0, 255, 0), Set_Properties(Vec3(100, 100), Vec3(100, 100))),
        SDL_Text(CopyMsg, font, Vec3(0, 0, 255), Set_Properties(Vec3(100, 100), Vec3(100, 150)))
    };
    tileCount = world.GetWorldData().tileCount;
    load(world.GetTiles(), testMessages, gameData);
    SDL_SetWindowTitle(m_window, gameData.title.c_str());
}

SDLWorld::~SDLWorld()
{
    delete[] tiles;
    delete[] words;
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
    SDL_RenderClear(m_renderer);

    for(int i = 0; i < tileCount; i++)
        Blit(tiles[i]);

    for(int i = 0; i < 3; i++)
        Blit(words[i]);

    SDL_RenderPresent( m_renderer );
    SDL_Delay(5000);
    code = 1;
}

SDL_Block SDLWorld::GetBlock(TileProperties tile, Vec3 Scale)
{
    SDL_Block block;
    block.color = tile.color;
    block.rect.properties= tile.properties;
    return block;
}

void SDLWorld::load(Tile tiles[], SDL_Text testWords[], Data_Game gameData){
    //int NumberOfTiles = sizeof(this->tiles);
    this->tiles = new SDL_Block[tileCount];
    for(int i = 0; i < tileCount; i++){
        this->tiles[i] = GetBlock(tiles[i].GetProperties(), Vec3(gameData.ScaleWidth, gameData.ScaleHeight, 0));
    }

    this->words = new SDL_Visual[3];
    for(int i = 0; i < 3; i++){
        this->words[i] = SDL_Visual(testWords[i], m_renderer);
    }
}
