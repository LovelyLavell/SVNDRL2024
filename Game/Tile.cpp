#include "Tile.h"
Tile::Tile(){
    id = 0;
}

Tile::Tile(unsigned int id, TileProperties tileProperties){
    this->id = id;
    this->tileProperties = tileProperties;
}

TileProperties Tile::GetProperties(){
    return tileProperties;
}

void Tile::Change(TileType type){
    tileProperties.type = type;
}
void Tile::Change(Vec3 color){
    tileProperties.color = color;
}
void Tile::Change(TileType type, Vec3 color){
    Change(type);
    Change(color);
    if(type == Floor)
        tileProperties.collision = false;
}
