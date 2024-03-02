#include "SDL.h"
#include "InitError.h"
#include "../Mapping/SDLMapping.h"
SDL::SDL( Data_Game gameData, Uint32 flags )
{

    //This is the same array as from the draw that's why I am using an int array in a weird way
    TransColors.Base.a = 246;
    TransColors.Base.b = 170;
    TransColors.Base.c = 185;

    TransColors.Back.a =  91;
    TransColors.Back.b = 207;
    TransColors.Back.c = 251;

    TransColors.Accent.a = 255;
    TransColors.Accent.b = 255;
    TransColors.Accent.c = 255;

    Vec3 colors[] = {
        TransColors.Base,
        TransColors.Back,
        TransColors.Accent,
        TransColors.Back,
        TransColors.Base
    };
    bars = new ColorBar[] {ColorBar(),ColorBar(),ColorBar(),ColorBar(),ColorBar()};
    for(int i = 0; i < 5; i++){
        //Setup rect
        bars[i].rect.properties.Size.a = gameData.WindowWidth;
        bars[i].rect.properties.Size.b = gameData.WindowHeight / 5;
        bars[i].rect.properties.Location.a = 0;
        bars[i].rect.properties.Location.b = bars[i].rect.properties.Size.b * i;

        //Setup colors
        bars[i].color = colors[i];
    }
    if ( SDL_Init( flags ) != 0 )
        throw InitError();

    if ( SDL_CreateWindowAndRenderer( gameData.WindowWidth, gameData.WindowHeight, SDL_WINDOW_SHOWN,
                                      &m_window, &m_renderer ) != 0 )
        throw InitError();
}

SDL::~SDL()
{
    delete(bars);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    SDL_Quit();
}

void SDL::draw()
{
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );

    for(long unsigned int i = 0; i < sizeof(bars); i++){

        SDL_SetRenderDrawColor( m_renderer, (int)bars[i].color.a, (int)bars[i].color.b, (int)bars[i].color.c, 255);
        SDL_Rect bar = SDLMapping().ToSDLRect(bars[i].rect);
        SDL_RenderFillRect( m_renderer, &bar);
        SDL_RenderPresent( m_renderer );
        SDL_Delay( 500 );
    }
}
