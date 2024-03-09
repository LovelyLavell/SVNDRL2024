#include "World.h"

WorldData World::GetWorldData(){
    return data;
}

World::TileSelection * World::SelectTile(Set_Properties zone){
    //First we calculate the initial index based on location
    int location = zone.Location.a + (data.width * zone.Location.b);
    //Then get the size of the zone and make the array
    int zoneSize = zone.Size.a * zone.Size.b;
    TileSelection * selection = new TileSelection[zoneSize];

    //I then go into two for loops to populate the selections
    int i = 0;
    for(int y = 0; y < zone.Size.b; y++){
        for(int x = 0; x < zone.Size.a; x++){
            selection[i].index = x + location + (y * data.width);
            selection[i].status = World::floor;
            i++;
        }
    }
    return selection;
}

void World::MakeLand(TileSelection * selection, int tileCount, Vec3 Color){
    for(int i = 0; i < tileCount; i++){
        int index = selection[i].index;
        data.Tiles[index].Change(Floor, Color);
    }
}
