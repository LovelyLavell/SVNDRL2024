#include "Startup.h"

Startup::Startup(int argc, char * argv[]){
    GameData.title = "In Essence: Bad Time";
    GameData.WindowWidth = 800;
    GameData.WindowHeight = 600;

    //Scaling required for the graphis of the game
    GameData.ScaleWidth = GameData.WindowWidth / GameData.DefaultWidth;
    GameData.ScaleHeight = GameData.WindowHeight / GameData.DefaultHeight;
}
