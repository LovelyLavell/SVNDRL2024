#include "Initial.h"
#include "../GRandom.h"
#include "../../Helpers/TMath.h"
#include "../Generation/TileGen.h"
#include "../Elements/Loot.h"
Initial::Initial(){
    Generate();
}

void Initial::Display(){
}

void Initial::Generate(){
    //Minimum dimensions for a level
    data.width = 25;
    data.height = 20;
    data.tileCount = data.width * data.height;
    data.Tiles = new Tile[data.tileCount];
    data.EntityCount = 7;
    data.Entities = new Entity*[data.EntityCount];
    TileGen generation;
    Vec3 waterColor = Vec3(0, 0, 255);
    int id = 0;
    for(int y = 0; y < tSize * data.height; y += tSize){
        for (int x = 0; x < tSize * data.width; x += tSize){
            Vec3 location;
            location.a = x;
            location.b = y;
            data.Tiles[id] = generation.GetWaterTile(id, location, waterColor, true);
            id++;
        }
    }
    Vec3 warp1;
    Vec3 warp2;
    if((int)GRandom::GetRandom(2) % 2 != 0){
        warp1 =Vec3(16, 8);
        warp2 = Vec3(21, 6);
        }
    else{
        warp2 = Vec3(16, 8);
        warp1 = Vec3(21, 6);
    }
    start.PlayerStart = Vec3(6, 13);
    TileSelection * selection = SelectTile(Set_Properties(Vec3(3, 10), Vec3 (5, 5)));
    MakeLand(selection, 30, Vec3(0, 255, 0));
    delete selection;

    selection = SelectTile(Set_Properties(Vec3(3, 10), Vec3 (20, 5)));
    MakeLand(selection, 30, Vec3(0, 255, 0));
    delete selection;

    selection = SelectTile(Set_Properties(Vec3(3, 3), Vec3 (10, 5)));
    MakeLand(selection, 9, Vec3(0, 255, 0));
    delete selection;
    data.Entities[0] = new Warp(2, TMath::Multiply(Vec3(11, 6), 32), TMath::Multiply(warp1, 32));

    selection = SelectTile(Set_Properties(Vec3(3, 3), Vec3 (10, 12)));
    MakeLand(selection, 9, Vec3(0, 255, 0));
    delete selection;
    data.Entities[1] = new Warp(3, TMath::Multiply(Vec3(11, 13), 32), TMath::Multiply(warp2, 32));

    selection = SelectTile(Set_Properties(Vec3(3, 4), Vec3 (15, 8)));
    MakeLand(selection, 12, Vec3(0, 255, 0));
    delete selection;
    data.Entities[2] = new Warp(4, TMath::Multiply(Vec3(16, 11), 32), TMath::Multiply(start.PlayerStart, 32));

    start.WarpLocation = Vec3 (21, 14);
    //Bridges
    selection = SelectTile(Set_Properties(Vec3(2, 1), Vec3 (8, 6)));
    MakeLand(selection, 2, Vec3(255, 200, 100));
    delete selection;

        selection = SelectTile(Set_Properties(Vec3(2, 1), Vec3 (8, 13)));
    MakeLand(selection, 2, Vec3(255, 200, 100));
    delete selection;

    data.Entities[3] = new NPC(5, TMath::Multiply(Vec3(22, 9), 32));


    data.Entities[4] = new NPC(6, TMath::Multiply(Vec3(22, 7), 32));

    data.Entities[5] = new NPC(7, TMath::Multiply(Vec3(22, 5), 32));

    data.Entities[6] = new Loot(8, TMath::Multiply(Vec3(16, 10), 32));
}

void Initial::Logic(){
}

Initial::~Initial(){
}
