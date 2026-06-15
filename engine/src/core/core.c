#include "core.h"

Boot_Core_InitializationStatus Boot_Core_Initialize(Boot_Core_InitializationFlags flags)
{
    Uint32 sdl_flags = 0;
    switch (flags)
    {
    case INITIALIZE_VIDEO:
        sdl_flags |= SDL_INIT_VIDEO;
        break;
    }
    int status = SDL_Init(sdl_flags);
    if (status)
    {
        return STATUS_ERROR;
    }
    return STATUS_OK;
}

int Boot_Core_PollEvent(Boot_Core_Events* event)
{
    SDL_Event sdl_event;
    int poll = SDL_PollEvent(&sdl_event);

    if (sdl_event.type == SDL_QUIT)
    {
        *event = QUIT;
    }

    if (sdl_event.type == SDL_KEYDOWN)
    {
        if (sdl_event.key.keysym.sym == SDLK_ESCAPE)
        {
            *event = QUIT;
        }
    }

    return poll;
}