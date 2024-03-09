#ifndef ENTITYPROPERTIES_H_INCLUDED
#define ENTITYPROPERTIES_H_INCLUDED
#include "../../Structs/Set_Properties.h"
//All entities make use of properties
struct EntityProperties{

    Set_Properties physicalInfo;
    Vec3 lastLocation;
    //Always starts at 100
    int health;
    //You get tired but don't (normally) lose magical energy
    //Attacks are a matter of stamina drain (or ammo in the case of light ranged weapons)
    int stamina;
    //For non living entities these will just be zero
    int crystals;
    int status;
    //How In Essence effects the entity
    float conductivity;
    EntityProperties(){
        health = 100;
        stamina = 100;

    }
};

#endif // ENTITYPROPERTIES_H_INCLUDED
