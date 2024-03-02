#ifndef SDLMAPPING_H_INCLUDED
#define SDLMAPPING_H_INCLUDED
#include <SDL.h>
#include "../Superfluous/structs/TRect.h"
/*
 * This reperesents the issue with using my own custom property classes despite lbraries having them.
 * When passed to the functions the libraries use I have to map them to the proper type.
 * I tell myself I do this to make my code more flexible, I have been able to reuse code from projects years ago because of this.
 * In reality I am just stubborn and I know that.
*/

class SDLMapping{
    public:
    SDL_Rect ToSDLRect(TRect rect);
};

#endif // SDLMAPPING_H_INCLUDED
