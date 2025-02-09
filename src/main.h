#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_

#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

SDL_Window *window;
SDL_Renderer *renderer;

Uint64 last_tick = 0;
Uint64 current_tick = 0;
float delta_time;

void update();
void render();

#include "entity.h"

Entity entities[MAX_ENTITIES];
int entities_size = 0;

#define ENTITIES_REGISTER(entity)     \
    entities[entities_size] = entity; \
    entities_size++;

#define ENTITIES_HANDLE_EVENT_ALL(event)    \
    for (int i = 0; i < entities_size; i++) \
    {                                       \
        entities[i].handle_event(event);    \
    }

#define ENTITIES_UPDATE_ALL(delta_time)     \
    for (int i = 0; i < entities_size; i++) \
    {                                       \
        entities[i].update(delta_time);     \
    }

#define ENTITIES_RENDER_ALL(renderer)       \
    for (int i = 0; i < entities_size; i++) \
    {                                       \
        entities[i].render(renderer);       \
    }

#define ENTITIES_DESTROY_ALL()              \
    for (int i = 0; i < entities_size; i++) \
    {                                       \
        entities[i].destroy();              \
    }

#include "player.h"

#endif