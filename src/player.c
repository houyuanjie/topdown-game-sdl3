#include "player.h"

static SDL_Texture *player_texture;
static const SDL_FRect sprite_postion = {.x = 17, .y = 14, .w = 15, .h = 18};

typedef struct Position
{
    float x;
    float y;
} Position;

static Position position = {.x = 0, .y = 0};

static void player_handle_event(SDL_Event *event)
{
}

static void player_update(float delta_time)
{
    const bool *keyboard_state = SDL_GetKeyboardState(NULL);

    if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_UP])
    {
        position.y -= 30 * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_DOWN])
    {
        position.y += 30 * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_LEFT])
    {
        position.x -= 30 * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_D] || keyboard_state[SDL_SCANCODE_RIGHT])
    {
        position.x += 30 * delta_time;
    }
}

static void player_render(SDL_Renderer *renderer)
{
    SDL_FRect player_position = {.x = position.x,
                                 .y = position.y,
                                 .w = sprite_postion.w,
                                 .h = sprite_postion.h};
    SDL_RenderTexture(renderer, player_texture, &sprite_postion, &player_position);
}

static void player_destroy()
{
}

Entity player_init(SDL_Renderer *renderer)
{
    player_texture = IMG_LoadTexture(renderer, CHAR_SPRITESHEET);
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);

    Entity player = {.handle_event = player_handle_event,
                     .update = player_update,
                     .render = player_render,
                     .destroy = player_destroy};

    return player;
}