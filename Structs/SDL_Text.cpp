#include "SDL_Text.h"
SDL_Text::SDL_Text(Data_Message message, TTF_Font * font, Vec3 color, Set_Properties properties)
{
    this->message = message;
    this->properties = properties;
    SDL_Color sdlcolor;
    sdlcolor.r = color.a;
    sdlcolor.g = color.b;
    sdlcolor.b = color.c;
    texture = TTF_RenderText_Solid(font, message.message.c_str(), sdlcolor);
}

SDL_Text::~SDL_Text(){
    delete texture;
}
