#ifndef SECTION_H_INCLUDED
#define SECTION_H_INCLUDED
#include "../Structs/Data_Game.h"
#include "../Generated/SDL.h"
#include "World.h"
/*
* This is the class that runs the game itself. It uses SDL to display the images and gets info from the player and world
*
* Plot is generated protag goes to visit a section on vacation
* in In Essence (not a typo) and it turns out it is really fucked up. They, as a
* follower of Mordidine and sworn protector decide to investigate.
*
* It's an Agatonian, (From Agathe)
*
* Not related to the Sadi story.
*
*/
class Section {
private:
    World * CurrentWorld;
    SDL * sdl;
    Data_Game gameData;
    void Advance(); //This loads the worlds
    World * Worlds;
public:
    Section(Data_Game gameData);
    int Run();
    ~Section();
};
#endif // SECTION_H_INCLUDED
