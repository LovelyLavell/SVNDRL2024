#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include "Structs/Action.h"
#include "Structs/Event.h"
#include "Structs/EntityProperties.h"
#include "Tile.h"
#include "Structs/Input.h"
enum EntityType{
    generic, //Should not happen, time is short, will happen
    warp,
    npc,
    loot
};

class Entity
{
protected:
    bool destroy;
    EntityProperties properties;
    //This determines interactions and attacks, really cutting it close here
    Vec3 Direction;
    Vec3 destination;
    //This is the thing that will represent the
    char symbol = 'G';
    EntityType type;
    int id; //The index required for SDL
    //Interaction stuff
    int intType;
    int value;
public:
    //Change these to property values if I have the time
    virtual void Logic(Tile * Tile,  int tileCount) {if(properties.health <= 0) active = false; Correct(Tile, tileCount);};
    virtual void Move();
    virtual void Correct(Tile * Tile, int tileCount);
    virtual void Control(Input input) {};
    //Oh boy a pointer to player, really cutting it for time here
    virtual void Evaluate(Entity * entity, Action * Action){};
    virtual void ModVal(int selection, int value);
    EntityType GetType(){return type;}
    Vec3 GetLocation(){return properties.physicalInfo.Location;}
    Vec3 GetDirection();
    int GetNextLocation(int TileSize, int Width);
    int GetIndex(int TileSize, int Width);
    char GetSymbol(){return symbol;}
    //This is the last few things I am adding to make the game work
    virtual Vec3 GetNewLoc(){return destination;};
    void MoveEntity(Vec3 Location){
        properties.physicalInfo.Location = Location;
    }
    int GetID(){
        return id;
    }
    int GetIntType(){
        return intType;
    }
    int GetVal(){
        return value;
    }
    //Normal interaction for NPCs
    virtual void Interact(int type, int val){properties.health -= val;};
    bool active = true;
};

#endif // ENTITY_H_INCLUDED
