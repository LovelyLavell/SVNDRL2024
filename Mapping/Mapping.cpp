#include "SDLMapping.h"
//I can't foresee mapping so many different things I need more than one CPP file
SDL_Rect SDLMapping::ToSDLRect(TRect rect){
    SDL_Rect returnValue;
    returnValue.w = rect.properties.Size.a;
    returnValue.h = rect.properties.Size.b;
    returnValue.x = rect.properties.Location.a;
    returnValue.y = rect.properties.Location.b;
    return returnValue;
}
