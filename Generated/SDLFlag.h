#ifndef SDLFLAG_H_INCLUDED
#define SDLFLAG_H_INCLUDED
#include "SDL.h"
#include "../Structs/SDL_Block.h"
#include "../Superfluous/structs/TRect.h"
#include "../Structs/Vec3.h"
#include "../Structs/Set_Color.h"
class SDLFlag final : public SDL
{
    Set_Color TransColors; //Same three colors every time baby
    //What can I say, I love my trans flag.
    SDL_Block * bars;
public:
    SDLFlag();
    SDLFlag( Data_Game gameData, Uint32 flags = 0 );
    ~SDLFlag() override;
    void draw() override;
};

#endif // SDLFLAG_H_INCLUDED
