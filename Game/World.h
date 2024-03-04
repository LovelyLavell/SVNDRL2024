#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED
#include "Tile.h"
#include "Entity.h"
/*
*So I plan on having three worlds that need to be completed for the game to count as "finished"
*If I have enough time i will add a fourth "world" which would just be an infinitly generating world
*you can keep playing in past the story boss
*
*Thinking is, I can keep the scope a lot tighter like this. Have a satisfying climax, and then maybe a LATE final boss if you are IN IT!
*/
class World
{
protected:
    //So, since this is grid based
    Tile * Tiles;
    Entity * Entities;
    int width;
    int height;
    int depth;
public:
    World(){};
    Tile * GetTiles(){return Tiles;}; //Do Better
    virtual void Generate(){};
    virtual void Logic(){};
    virtual void Display(){};
    virtual ~World(){};
};

#endif // WORLD_H_INCLUDED
