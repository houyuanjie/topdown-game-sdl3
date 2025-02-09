#include "main.h"

/* Topdown Advanced Game
  See: https://o-lobster.itch.io/adventure-pack
  See: https://www.youtube.com/playlist?list=PLgBHxhPr3AsUlkPhMA9xgX_EyEmlwxcJd */

/* SDL3 Lifecycle Functions
  See: https://wiki.libsdl.org/SDL3/README/main-functions */

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Error initializing SDL: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    window = SDL_CreateWindow("SDL3 Game", 800, 600, 0);
    if (!window)
    {
        SDL_Log("Error creating window: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
    {
        SDL_Log("Error creating renderer: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    ENTITIES_REGISTER(player_init(renderer));

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    update();
    render();

    return SDL_APP_CONTINUE;
}

void update()
{
    last_tick = current_tick;
    current_tick = SDL_GetTicks();
    delta_time = (current_tick - last_tick) / 1000.0f;

    ENTITIES_UPDATE_ALL(delta_time);
}

void render()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    ENTITIES_RENDER_ALL(renderer);

    SDL_RenderPresent(renderer);
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        SDL_Log("Quitting SDL3 Game.\n");
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    ENTITIES_DESTROY_ALL();

    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}