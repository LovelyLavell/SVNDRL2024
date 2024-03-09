#include "Entity.h"
#include "../Helpers/TMath.h"
void Entity::ModVal(int selection, int value){}
Vec3 Entity::GetDirection(){return Direction;}
//I'm aware of operator overloads, I just don't think it's
//needed right now
int Entity::GetNextLocation(int TileSize, int Width)
{
    Vec3 Matrix = TMath::Divide(TMath::Add(properties.physicalInfo.Location, Direction), (float)TileSize);
    return Matrix.a + (Matrix.b * Width);
}
void Entity::Correct(Tile * Tile, int tileCount) {
    if(properties.physicalInfo.Location.a < 0)
        properties.physicalInfo.Location.a = 0;

    if(properties.physicalInfo.Location.b < 0)
        properties.physicalInfo.Location.b = 0;

    if(properties.physicalInfo.Location.a > 768)
        properties.physicalInfo.Location.a = 768;

    if(properties.physicalInfo.Location.b > 600)
        properties.physicalInfo.Location.b = 600;

    while((int)properties.physicalInfo.Location.a % 32 != 0){
        properties.physicalInfo.Location.a--;
    }
    while((int)properties.physicalInfo.Location.b % 32 != 0){
        properties.physicalInfo.Location.b--;
    }
    for(int i = 0; i < tileCount; i++){
        if(Tile[i].GetProperties().collision && (TMath::Equals(Tile[i].GetProperties().properties.Location, properties.physicalInfo.Location) || GetIndex(32, 25) == i))
        {
            properties.physicalInfo.Location = properties.lastLocation;
            break;
        }
    }
};
int Entity::GetIndex(int TileSize, int Width)
{
    Vec3 Matrix = TMath::Divide(properties.physicalInfo.Location, (float)TileSize);
    return Matrix.a + (Matrix.b * Width);
}
void Entity::Move(){
    properties.lastLocation = properties.physicalInfo.Location;
    Direction = TMath::Multiply(Direction, 32);
    properties.physicalInfo.Location = TMath::Add(properties.physicalInfo.Location, Direction);
}
