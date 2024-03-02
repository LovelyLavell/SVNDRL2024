#ifndef STARTUP_H_INCLUDED
#define STARTUP_H_INCLUDED
#include "../Structs/Data_Game.h"
//This takes care of populating all of the informaton about the game into various structures
class Startup{
    Data_Game GameData;
    void Interpret(int argc, char * argv[]);
public:
    Startup(int argc, char * argv[]);
    //Getters no setters
    Data_Game GetGameData();
};
#endif // STARTUP_H_INCLUDED
