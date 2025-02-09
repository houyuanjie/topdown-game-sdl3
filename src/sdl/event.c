#include "event.h"

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        SDL_Log("Good bye!\n");
        return SDL_APP_SUCCESS;
    }

    ENTITIES_HANDLE_EVENT_ALL(event);

    return SDL_APP_CONTINUE;
}