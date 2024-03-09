#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "../Tile.h"
#include "../Entity.h"
#include "../Structs/StartInfo.h"
class Player : public Entity
{
    //This is how the game is progressed
    StartInfo info;
    int playerCode;
public:
    void SetStart(StartInfo info);
    void Reset();
    void Advance();
    //void Move() override;
    void Logic(Tile * Tile, int tileCount) override;
    void Control(Input input) override;
    int GetCode(){return playerCode;}
    void DMG(int val){properties.health += val; if(properties.health > 100) properties.health = 100;};
    int GetHP(){return properties.health;};
};

#endif // PLAYER_H_INCLUDED
