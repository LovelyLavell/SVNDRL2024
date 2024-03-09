#include "SDLMapping.h"
//I can't foresee mapping so many different things I need more than one CPP file
SDL_Rect SDLMapping::ToSDLRect(TRect rect){
    SDL_Rect returnValue;
    //Pretty sure this is UV data
    returnValue.w = rect.properties.Size.a;
    returnValue.h = rect.properties.Size.b;
    returnValue.x = rect.properties.Location.a;
    returnValue.y = rect.properties.Location.b;
    return returnValue;
}

SDL_Rect SDLMapping::ToSDLRect(Set_Properties properties){
    SDL_Rect returnValue;
    //Pretty sure this is UV data
    returnValue.w = properties.Size.a;
    returnValue.h = properties.Size.b;
    returnValue.x = properties.Location.a;
    returnValue.y = properties.Location.b;
    return returnValue;
}

SDL_Rect * SDLMapping::ToSDLRectPtr(Set_Properties properties){
    SDL_Rect * returnValue = new SDL_Rect();
    //Pretty sure this is UV data
    returnValue->w = properties.Size.a;
    returnValue->h = properties.Size.b;
    returnValue->x = properties.Location.a;
    returnValue->y = properties.Location.b;
    return returnValue;
}

SDL_Rect * SDLMapping::ToSDLRectPtr(TRect rect){
    SDL_Rect * returnValue = new SDL_Rect();
    //Pretty sure this is UV data
    returnValue->w = rect.properties.Size.a;
    returnValue->h = rect.properties.Size.b;
    returnValue->x = rect.properties.Location.a;
    returnValue->y = rect.properties.Location.b;
    return returnValue;
}
