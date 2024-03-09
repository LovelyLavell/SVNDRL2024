#ifndef TILEGEN_H_INCLUDED
#define TILEGEN_H_INCLUDED
#include "../Tile.h"

class TileGen{
    TileDecalType ResolveDecal(unsigned int type);
    Vec3 GetStandardSize();
    //The initial tile info
    TileProperties Basic(unsigned int id, Vec3 location, TileType type);
public:

    //Doesn't really have a place anymore, the game was gonna be psudo 3D
    Tile GetAir(unsigned int id, Vec3 location);
    //Something the player can walk over
    Tile GetFloorTile(unsigned int id, Vec3 location, Vec3 color);
    //Some can be walked over some can't, I will make them different colors. It'll really just be the essential ocean.
    Tile GetWaterTile(unsigned int id, Vec3 location, Vec3 color, bool collision = false);
    //These block you, there is code for breakability but I don't think it's worth it
    Tile GetWallTile(unsigned int id, Vec3 location, Vec3 color, int hardness = 0);
};

#endif // TILEGEN_H_INCLUDED
