#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED
#include "../Structs/Set_Properties.h"
#include "../Structs/Vec3.h"
#include "Structs/TileProperties.h"
//Though items, npcs, and the player will all be entities tiles will be completely seperate due to functioning differently.
class Tile{
    unsigned int id;
    TileProperties tileProperties;
    public:
    Tile();
    Tile(unsigned int id, TileProperties tileProperties);
    //Really the only two important values unless I have enough time
    //to add extra data to tiles but I don't see that.
    Vec3 GetLocation();
    TileProperties GetProperties();
};

#endif // TILE_H_INCLUDED
