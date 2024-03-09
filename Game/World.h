#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED
#include "Tile.h"
#include "Entity.h"
#include "Elements/NPC.h"
#include "Structs/WorldData.h"
#include "Elements/Warp.h"
#include "Structs/StartInfo.h"
/*
*So I plan on having three worlds that need to be completed for the game to count as "finished"
*If I have enough time i will add a fourth "world" which would just be an infinitly generating world
*you can keep playing in past the story boss
*
*Thinking is, I can keep the scope a lot tighter like this. Have a satisfying climax, and then maybe a LATE final boss if you are IN IT!
*/
class World
{
protected:
    enum SelectionStatus{
        floor,
        wall,
        enemy,
        chest,
    };
    struct TileSelection{
        int index;
        SelectionStatus status;
    };
    Set_Properties * zones;
    const int tSize = 32;
    WorldData data;
    StartInfo start;
    TileSelection* SelectTile(Set_Properties zone);
    void MakeLand(TileSelection * selection, int tileCount, Vec3 Color);
public:
    World(){};
    Tile * GetTiles(){return data.Tiles;}; //Do Better
    virtual void Generate(){};
    virtual void Logic(){};
    virtual void Display(){};
    virtual ~World(){};
    StartInfo GetStartInfo(){return start;}
    WorldData GetWorldData();
};

#endif // WORLD_H_INCLUDED
