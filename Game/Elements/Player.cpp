#include "Player.h"
#include "../../Helpers/TMath.h"
void Player::Logic(Tile * Tile, int tileCount){
    if(TMath::Equals(properties.physicalInfo.Location,TMath::Multiply(info.WarpLocation, 32)))
        playerCode = 1;
    Correct(Tile, tileCount);
}
void Player::SetStart(StartInfo info){
    this->info = info;
    properties.physicalInfo.Location = TMath::Multiply(info.PlayerStart, 32);
}
void Player::Advance(){
    playerCode = 0;
}
void Player::Reset(){
    symbol = '@';
    playerCode = 0;
}
void Player::Control(Input input){
    Direction = Vec3(0, 0, 0);
    if(!input.input) return;
    if(input.w)
        Direction.b = -1;
    if(input.a)
        Direction.a = -1;
    if(input.s)
        Direction.b = 1;
    if(input.d)
        Direction.a = 1;
}
