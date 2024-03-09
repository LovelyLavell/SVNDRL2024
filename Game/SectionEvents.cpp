#include "Section.h"

Input Section::ReadKeys(SDL_KeyboardEvent k_event){
    Input input;
    input.input = true;
    switch(k_event.keysym.sym){
        default: break;
        case SDLK_w: input.w = true; break;
        case SDLK_a: input.a = true; break;
        case SDLK_s: input.s = true; break;
        case SDLK_d: input.d = true; break;
        case SDLK_ESCAPE: input.esc = true; break;
    }
    return input;
}
void Section::ReadWindow(SDL_WindowEvent w_event){
    if(w_event.event == SDL_WINDOWEVENT_CLOSE)
        close = true;
}

bool Section::ReadInteraction(int EntityId, EntityType type){
    switch(type){
        default: break;
        case warp: player.MoveEntity(world->GetWorldData().Entities[EntityId]->GetNewLoc()); return true;
        case loot: player.DMG(50 - (2 * stage)); return false;
        case npc: world->GetWorldData().Entities[EntityId]->Interact(0, player.GetVal()); player.DMG(-(25 + (2 * stage))); return false;
    }
    return true;
}
