#ifndef WORLDDATA_H_INCLUDED
#define WORLDDATA_H_INCLUDED
#include "../Entity.h"
#include "../Tile.h"
#include "../Elements/NPC.h"
struct WorldData{
    //So, since this is grid based
    Tile * Tiles;
    Entity ** Entities;
    NPC ** NPCs;
    int NPCCount;
    int EntityCount;
    int tileCount;
    int width;
    int height;
    int depth;
};

#endif // WORLDDATA_H_INCLUDED
