#include <exception>
#include <string>
#include <iostream>
#include "Generated/SDL.h"
#include "Systems/Startup.h"
#include "Generated/InitError.h"
int main( int argc, char * argv[] )
{
    Startup start(argc, argv);
    try
    {
        SDL sdl( start.GetGameData(), SDL_INIT_VIDEO | SDL_INIT_TIMER );
        sdl.draw();

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
