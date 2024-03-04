#include "Test.h"
#include "../Generation/TileGen.h"
Test::Test(){
    Generate();
}

void Test::Display(){
}

void Test::Generate(){
    width = 10;
    height = 10;
    Tiles = new Tile[10 * 10];
    TileGen generation;
    int id = 0;
    for(int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            Vec3 location;
            location.a = x * 10;
            location.b = y * 10;
            Tiles[id] = generation.GetAir(id, location);
            id++;
        }
    }
}

void Test::Logic(){
}

Test::~Test(){
}

