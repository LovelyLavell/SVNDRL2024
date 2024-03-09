#include "TileGen.h"
TileDecalType TileGen::ResolveDecal(unsigned int decal){
    return none; //no decals so it doesn't matter right now
}

Vec3 TileGen::GetStandardSize(){
    return Vec3(32, 32, 32);
}

TileProperties TileGen::Basic(unsigned int id, Vec3 location, TileType type){
    TileProperties properties;
    properties.properties.Location = location;
    properties.properties.Size = GetStandardSize();
    properties.type = type;
    properties.decal = ResolveDecal(properties.type);
    return properties;
}

Tile TileGen::GetAir(unsigned int id, Vec3 location){
    TileProperties properties = Basic(id, location, Air);
    properties.color = Vec3(25, 25, 25);
    return Tile(id, properties);
}

Tile TileGen::GetFloorTile(unsigned int id, Vec3 location, Vec3 color){
    TileProperties properties = Basic(id, location, Floor);
    properties.color = color;
    properties.collision = false;
    return Tile (id, properties);
}

Tile TileGen::GetWaterTile(unsigned int id, Vec3 location, Vec3 color, bool collision){
    TileProperties properties = Basic(id, location, Water);
    properties.color = color;
    properties.collision = collision;
    return Tile (id, properties);
}

Tile TileGen::GetWallTile(unsigned int id, Vec3 location, Vec3 color, int hardness){
    TileType type;
    switch(hardness){
        default: type = Brittle; break;
        case 0: type = Hard; break;
        case 1: type = Soft; break;
    }
    TileProperties properties = Basic(id, location, type);
    properties.color = color;
    properties.collision = true;
    return Tile (id, properties);
}
