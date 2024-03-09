#include "SDL_Visual.h"
#include "Vec3.h"
SDL_Visual::SDL_Visual(SDL_Text text, SDL_Renderer * m_renderer){
    UV = TRect(Vec3(0, 0), text.properties.Size);
    location = TRect(text.properties);
    image = SDL_CreateTextureFromSurface(m_renderer,text.texture);
}

SDL_Visual::SDL_Visual(Data_Message text, TTF_Font * font, SDL_Renderer * m_renderer){

    SDL_Text Data(text, font, Vec3(255, 0, 0), Set_Properties(Vec3(300, 100), Vec3(0, 0)));


    UV = TRect(Vec3(0, 0), Data.properties.Size);
    location = TRect(Data.properties);
    image = SDL_CreateTextureFromSurface(m_renderer,Data.texture);
}

SDL_Visual::SDL_Visual(char symbol, Vec3 color, Vec3 location, TTF_Font * font, SDL_Renderer * m_renderer){
    UV = TRect(Vec3(0, 0), Vec3(32, 32));
    this->location = TRect(location, Vec3(32, 32));
    SDL_Color sdlcolor;
    sdlcolor.r = color.a;
    sdlcolor.g = color.b;
    sdlcolor.b = color.c;
    SDL_Surface * text = TTF_RenderText_Solid(font, std::string(1, symbol).c_str(), SDL_Color(sdlcolor));
    image = SDL_CreateTextureFromSurface(m_renderer,text);
    delete text;
}
