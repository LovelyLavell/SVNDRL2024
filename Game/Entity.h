#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include "Structs/Action.h"
#include "Structs/Event.h"
class Entity
{
    bool destroy;
    bool active;
public:
    void Logic(Tile * Tile);
    void Evaluate(Entity * Entity, Action * Action);
};

#endif // ENTITY_H_INCLUDED
