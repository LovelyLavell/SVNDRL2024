#include <exception>
#include <string>
#include <iostream>
#include "Section.h"
#include "../Generated/InitError.h"
#include "Worlds/Lands.h"
#include "Worlds/Test.h"
#include "../Generated/SDLFlag.h"
#include "../Generated/SDLWorld.h"
Section::Section(Data_Game gameData)
{
    SDLWorld * world = new SDLWorld(gameData, SDL_INIT_VIDEO | SDL_INIT_TIMER );

    Worlds = new World[4]{Test(), Lands(), Lands(), Lands()};
    Worlds[0].Generate();
    world->load(Worlds[0].GetTiles());
    sdl = world;
}

int Section::Run()
{
    try
    {
        sdl->draw();
        return 0;
    }
    catch ( const InitError & err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
    }
    return 1;
}

Section::~Section()
{
    delete[] Worlds;
    delete sdl;
}
