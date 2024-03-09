#include "Test.h"
#include "../Generation/TileGen.h"
Test::Test(){
    Generate();
}

void Test::Display(){
}

void Test::Generate(){
    //Minimum dimensions for a level
    data.width = 25;
    data.height = 20;
    data.tileCount = data.width * data.height;
    data.Tiles = new Tile[data.tileCount];
    TileGen generation;
    Vec3 color;
    int id = 0;
    for(int y = 0; y < tSize * data.height; y += tSize){
        for (int x = 0; x < tSize * data.width; x += tSize){
            //I want to know how to just make a color grid
            //I know there is code for it out there
            //but ideally I should be able to bust something
            //like that out. For now, it is grayscale
            color.a = color.b = color.c += (1 + (255 / data.tileCount));
            if(color.a > 255)
                color.a = color.b = color.c = 255;
            Vec3 location;
            location.a = x;
            location.b = y;
            data.Tiles[id] = generation.GetFloorTile(id, location, color);
            id++;
        }
    }

    TileSelection * selection = SelectTile(Set_Properties(Vec3(3, 3), Vec3 (5, 5)));
    MakeLand(selection, 9, Vec3(0, 255, 0));
    delete selection;

}

void Test::Logic(){
}

Test::~Test(){
}
