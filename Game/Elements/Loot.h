#ifndef LOOT_H_INCLUDED
#define LOOT_H_INCLUDED

#include "../Entity.h"
class Loot : public Entity
{
public:
    Loot(int id, Vec3 Location)
    {
        properties.physicalInfo.Location = Location;
        symbol = '$';
        this->destination = destination;
        type = loot;
        this->id = id;
    }
};

#endif // LOOT_H_INCLUDED
