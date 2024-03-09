#ifndef SDL_TEXT_H_INCLUDED
#define SDL_TEXT_H_INCLUDED
#include "Data_Message.h"
#include "Set_Properties.h"
#include <SDL.h>
#include <SDL_ttf.h>
struct SDL_Text
{
    Data_Message message;
    SDL_Surface * texture; //Needs to be freed
    Set_Properties properties;
    SDL_Text(Data_Message message, TTF_Font * font, Vec3 color, Set_Properties properties);
    ~SDL_Text();
};

#endif // SDL_TEXT_H_INCLUDED
