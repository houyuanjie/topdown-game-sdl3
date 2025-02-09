#pragma once
#ifndef _SDL_ITERATE_H_

#include <SDL3/SDL.h>

#include "appstate.h"

#include "../entity.h"

void update(AppState *state);
void render(AppState *state);

#endif