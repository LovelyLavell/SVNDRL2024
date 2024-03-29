#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED
#include <SDL.h>
#include "../Structs/Data_Game.h"
#include "../Mapping/SDLMapping.h"
#include "../Structs/SDL_Visual.h"
#include "../Structs/SDL_Block.h"
#include "../Game/Structs/WorldData.h"
//This is the SDL class generated by code::blocks with a few adjustments by me
class SDL
{
protected:
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    SDLMapping SDLMap;
    //Get's a signal from SDL itself
    int code = 0;
public:
    SDL();
    SDL( Data_Game gameData, Uint32 flags = 0 );
    virtual ~SDL(){};
    virtual void draw(){};
    virtual void update(int i, Vec3 loc, bool show){};
    //Very late addition, not good
    virtual void load(WorldData data, Data_Game gameData){};
    void Blit(SDL_Visual visual);
    void Blit(SDL_Block block);
    int GetCode(){return code;}
};
#endif // SDL_H_INCLUDED
