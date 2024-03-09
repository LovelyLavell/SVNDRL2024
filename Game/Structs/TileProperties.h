#ifndef TILEPROPERTIES_H_INCLUDED
#define TILEPROPERTIES_H_INCLUDED
#include "../Enums/TileTypes.h"
#include "../Enums/TileDecalType.h"
#include "../../Structs/Vec3.h"
#include "../../Structs/Set_Properties.h"
struct TileProperties{
    //Health Properties
    int Health; //Always 100 but I don't want to set anything in the header
    int Threshold; //Point at which it can take dmg
    float Resistance; //Usually 1, goes down to 0, nullifies dmg.
    bool collision; //If entities can collide with this
    Set_Properties properties;
    Vec3 color; //So, the most efficient way for me to design this is to texture only entities and keep the tiles just colors, hopefully it doesn't impact performance too much.
    TileDecalType decal; //This is for, like, waves for water, dots for sand, etc.
    TileType type;
    TileProperties();
};

#endif // TILEPROPERTIES_H_INCLUDED
