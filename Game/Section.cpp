#include <exception>
#include <string>
#include <iostream>
#include "Section.h"
#include "../Generated/InitError.h"
#include "Worlds/Lands.h"
#include "Worlds/Test.h"
#include "../Generated/SDLFlag.h"
#include "../Generated/SDLWorld.h"
#include "RenderSDL.h"
#include "../Structs/SDL_Text.h"
#include "Worlds/Initial.h"
#include "../Helpers/TMath.h"
#include "GRandom.h"
#include <iostream>
Section::Section(Data_Game gameData)
{
    this->gameData = gameData;
    //Worlds = new World[4]{Test(), Lands(), Lands(), Lands()};
    sdl = new RenderSDL(gameData, SDL_INIT_VIDEO | SDL_INIT_TIMER );
    //If this ever changes there is an error
    Reset();
    SDLCode = 0;
    GRandom::Seed();
}
void Section::Advance(){
    stage++;
    player.Advance();
    world = new Initial();
    //world->Generate();
    sdl->load(world->GetWorldData(), gameData);
    player.Reset();
    player.SetStart(world->GetStartInfo());
    sdl->update(1, TMath::Multiply(world->GetStartInfo().WarpLocation, 32), true);
}
void Section::SetInfo(){
    std::string addition;
    switch(stage){
        default: addition = "1"; break;
        case 1: addition = "2";break;
        case 2: addition = "3";break;
        case 3: addition = "4";break;
        case 4: addition = "5";break;
        case 5: addition = "6";break;
        case 6: addition = "7";break;
        case 7: addition = "8";break;
        case 8: addition = "9";break;
        case 9: addition = "Final stage";break;
    }
    if(player.GetHP() <= 25)
        addition += " You are dying";

    else if(player.GetHP() <= 50)
        addition += " You are wounded";

    else if(player.GetHP() <= 75)
        addition += " You were hit";

    else addition += " You are fine";

    std::string msg = "Stage: " + addition;
    Data_Message infoMsg("System", msg, 0);
    sdl->info = SDL_Visual(infoMsg, sdl->GetFont(),sdl->GetRender());
}
void Section::Reset(){
    stage = 0;
    world = new Initial();
    world->Generate();
    sdl->load(world->GetWorldData(), gameData);
    player.Reset();
    player.SetStart(world->GetStartInfo());
    sdl->update(1, TMath::Multiply(world->GetStartInfo().WarpLocation, 32), true);
}
int Section::Run()
{
    try
    {
    do{
        do{
            SetInfo();
            bool doAction = false;
            Input inputs;
            SDL_Event event;
            while(SDL_PollEvent(&event)){
                switch(event.type){
                    case SDL_KEYUP:
                        doAction = true;
                        inputs = ReadKeys(event.key);
                    break;
                    case SDL_WINDOWEVENT:
                        ReadWindow(event.window);
                    break;
                    default: break;
                }
            }
            player.Control(inputs);
            player.Move();
            player.Logic(world->GetTiles(), world->GetWorldData().tileCount);
            for(int i = 0; i < world->GetWorldData().EntityCount; i++){
                sdl->update(world->GetWorldData().Entities[i]->GetID(), world->GetWorldData().Entities[i]->GetLocation(), world->GetWorldData().Entities[i]->active);
                if(!doAction || !world->GetWorldData().Entities[i]->active)
                    continue;
                if(TMath::Equals(player.GetLocation(), world->GetWorldData().Entities[i]->GetLocation())){
                    world->GetWorldData().Entities[i]->active = ReadInteraction(i, world->GetWorldData().Entities[i]->GetType());
                }
                world->GetWorldData().Entities[i]->Move();
                world->GetWorldData().Entities[i]->Logic(world->GetTiles(), world->GetWorldData().tileCount);
            }
            sdl->update(0, player.GetLocation(), true);
            sdl->draw();
            if(inputs.esc)
                close = true;
            }while(sdl->GetCode() == 0 && !close && player.GetCode() == 0 && player.GetHP() > 0);
            Advance();
        }while(sdl->GetCode() == 0 && !close && stage < 10 && player.GetHP() > 0);

        return SDLCode;
    }
    catch ( const InitError & err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
    }
    return -1;
}

Section::~Section()
{
    delete sdl;
}
