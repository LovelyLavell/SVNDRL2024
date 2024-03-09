#include "SDL.h"
SDL::SDL(){
    m_window = nullptr;
    m_renderer = nullptr;
}
void SDL::Blit(SDL_Visual visual){
    SDL_Rect * disposeUV = SDLMap.ToSDLRectPtr(visual.UV);
    SDL_Rect * disposeClip = SDLMap.ToSDLRectPtr(visual.location);
    SDL_RenderCopy(m_renderer, visual.image, nullptr, disposeClip);
    delete disposeUV;
    delete disposeClip;
}

void SDL::Blit(SDL_Block block){
    SDL_SetRenderDrawColor( m_renderer, (int)block.color.a, (int)block.color.b, (int)block.color.c, 255);
    SDL_Rect bar = SDLMapping().ToSDLRect(block.rect);
    SDL_RenderFillRect( m_renderer, &bar);
}
