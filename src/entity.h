#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <SDL3/SDL.h>

#define MAX_ENTITIES 100

typedef struct Entity
{
    void (*handle_event)(SDL_Event *event);
    void (*update)(float delta_time);
    void (*render)(SDL_Renderer *renderer);
    void (*destroy)(void);
} Entity;

#endif