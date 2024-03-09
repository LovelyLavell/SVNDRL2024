#ifndef SDL_VISUAL_H_INCLUDED
#define SDL_VISUAL_H_INCLUDED
#include "SDL_Text.h"
#include "../Superfluous/structs/TRect.h"
struct SDL_Visual{
    //The rect can be used to dictate the UVs
    TRect UV;
    //This is both size and location
    TRect location;
    //This, for now, will just hold an image
    SDL_Texture * image;
    SDL_Visual(SDL_Text text, SDL_Renderer * m_renderer);

    SDL_Visual(Data_Message text, TTF_Font * font, SDL_Renderer * m_renderer);
    SDL_Visual(char symbol, Vec3 color, Vec3 location, TTF_Font * font, SDL_Renderer * m_renderer);
    SDL_Visual(){}
};

#endif // SDL_VISUAL_H_INCLUDED
