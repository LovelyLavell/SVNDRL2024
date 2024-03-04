#include "Generated/SDL.h"
#include "Systems/Startup.h"
#include "Game/Section.h"
int main( int argc, char * argv[] )
{
    Startup start(argc, argv);
    Section section(start.GetGameData());
    switch(section.Run()){
        default: break;
    }
    return 0;
}
