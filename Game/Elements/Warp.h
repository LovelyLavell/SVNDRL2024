#ifndef WARP_H_INCLUDED
#define WARP_H_INCLUDED
#include "../Entity.h"
#include "../../Helpers/TMath.h"
class Warp : public Entity{
    public:
    Warp(int id, Vec3 location, Vec3 destination){
        properties.physicalInfo.Location = location;
        symbol = '&';
        this->destination = destination;
        type = warp;
        this->id = id;
    }
};

#endif // WARP_H_INCLUDED
