#include "TileGen.h"
TileDecalType TileGen::ResolveDecal(unsigned int decal){
    return none; //no decals so it doesn't matter right now
}

Tile TileGen::GetAir(unsigned int id, Vec3 location){
    TileProperties properties;
        properties.type = Air;
        properties.decal = ResolveDecal(properties.type);
        properties.Location = location;
    Tile retValue(id, properties);
    return retValue;
}

Tile TileGen::GetBasicTile(unsigned int id, Vec3 location, Vec3 color){
    TileProperties properties;
        properties.color = color;
        properties.Location = location;
    Tile retValue(id, properties);
    return retValue;
}

Tile TileGen::GetWaterTile(unsigned int id, Vec3 location, Vec3 color){
    TileProperties properties;
        properties.type = Water;
        properties.color = color;
        properties.decal = ResolveDecal(properties.type);
        properties.Location = location;
    Tile retValue(id, properties);
    return retValue;
}
