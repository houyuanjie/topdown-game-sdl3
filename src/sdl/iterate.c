#include "iterate.h"

SDL_AppResult SDL_AppIterate(void *appstate)
{
    update((AppState *)appstate);
    render((AppState *)appstate);

    return SDL_APP_CONTINUE;
}

void update(AppState *state)
{
    state->last_tick = state->current_tick;
    state->current_tick = SDL_GetTicks();
    state->delta_time = (state->current_tick - state->last_tick) / 1000.0f;

    ENTITIES_UPDATE_ALL(state->delta_time);
}

void render(AppState *state)
{
    SDL_RenderClear(state->renderer);
    SDL_SetRenderDrawColor(state->renderer, 0, 255, 0, 255);

    ENTITIES_RENDER_ALL(state->renderer);

    SDL_RenderPresent(state->renderer);
}