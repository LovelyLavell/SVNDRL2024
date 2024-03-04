#ifndef TILEGEN_H_INCLUDED
#define TILEGEN_H_INCLUDED
#include "../Tile.h"

class TileGen{
    TileDecalType ResolveDecal(unsigned int type);
public:
    //The most basic form of tile. A simple air block
    Tile GetAir(unsigned int id, Vec3 location);
    //Makes a tile and fills up the basic information for it
    Tile GetBasicTile(unsigned int id, Vec3 location, Vec3 color);
    Tile GetWaterTile(unsigned int id, Vec3 location, Vec3 color);

    //Destruction tiles, might not be needed
};

#endif // TILEGEN_H_INCLUDED
