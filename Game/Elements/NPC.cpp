#include "NPC.h"
#include "../../Helpers/TMath.h"
#include "../GRandom.h"
NPC::NPC(int id, Vec3 location){
    properties.physicalInfo.Location = location;
    symbol = 'X';
    this->destination = destination;
    this->id = id;
    type = npc;
}

void NPC::Move(){
    properties.lastLocation = properties.physicalInfo.Location;

    if((int)GRandom::GetRandom(2) == 0)
        Direction.a = 1;

    else if(((int)GRandom::GetRandom(1) == 0))
        Direction.a = -1;

    else Direction.a = 0;

    if((int)GRandom::GetRandom(2) == 0)
        Direction.b = 1;

    else if(((int)GRandom::GetRandom(1) == 0))
        Direction.b = -1;

    else Direction.b = 0;


    Direction = TMath::Multiply(Direction, 32);
    properties.physicalInfo.Location = TMath::Add(properties.physicalInfo.Location, Direction);
}
