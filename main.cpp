#include "Generated/SDLFlag.h"
#include "Systems/Startup.h"
#include "Game/Section.h"
int main( int argc, char * argv[] )
{
    Startup start(argc, argv);
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1 || TTF_Init() == -1)
        return -1;
    SDLFlag flag(start.GetGameData(), SDL_INIT_VIDEO | SDL_INIT_TIMER );
    flag.draw();
    SDL_Quit();
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1 || TTF_Init() == -1)
        return -1;


    Section section(start.GetGameData());
    switch(section.Run()){
        default: break;
    }
    return 0;
}
