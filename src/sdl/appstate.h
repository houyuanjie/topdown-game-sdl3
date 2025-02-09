#pragma once
#ifndef _SDL_APPSTATE_H_
#define _SDL_APPSTATE_H_

#include <SDL3/SDL.h>

typedef struct AppState
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    Uint64 last_tick;
    Uint64 current_tick;
    float delta_time;
} AppState;

#endif