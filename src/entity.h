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

extern Entity entities[MAX_ENTITIES];
extern int entities_size;

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

#endif