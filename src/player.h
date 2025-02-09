#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "entity.h"
#include "assets.h"

Entity player_init(SDL_Renderer *renderer);

#endif