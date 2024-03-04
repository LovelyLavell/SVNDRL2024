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
