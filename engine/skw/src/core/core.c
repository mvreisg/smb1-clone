#include "core/core.h"

SKW_Core_InitializationStatus SKW_Core_Initialize(SKW_Core_InitializationFlags flags)
{
    Uint32 sdl_flags = 0;
    switch (flags)
    {
    case SKW_INITIALIZE_VIDEO:
        sdl_flags |= SDL_INIT_VIDEO;
        break;
    }
    int status = SDL_Init(sdl_flags);
    if (status)
    {
        return SKW_ERROR;
    }
    return SKW_OK;
}

int SKW_Core_PollEvent(SKW_Core_Events* event, SKW_Core_KeyEvent_KeyCode* key_code)
{
    SDL_Event sdl_event;
    int poll = SDL_PollEvent(&sdl_event);

    if (sdl_event.type == SDL_QUIT)
    {
        *event = SKW_QUIT;
    }

    if (sdl_event.type == SDL_KEYDOWN)
    {
        if (sdl_event.key.keysym.sym == SDLK_ESCAPE)
        {
            *event = SKW_QUIT;
            *key_code = SKW_ESCAPE;
        }
    }

    return poll;
}

void SKW_Core_Delay(Uint32 milliseconds)
{
    SDL_Delay(milliseconds);
}

void SKW_Core_Quit()
{
    SDL_Quit();
}