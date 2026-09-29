#include "core/core.h"

Engine_Core_InitializationStatus Engine_Core_Initialize(Engine_Core_InitializationFlags flags)
{
    Uint32 sdl_flags = 0;
    switch (flags)
    {
    case ENGINE_INITIALIZE_VIDEO:
        sdl_flags |= SDL_INIT_VIDEO;
        break;
    }
    int status = SDL_Init(sdl_flags);
    if (status)
    {
        return ENGINE_ERROR;
    }
    return ENGINE_OK;
}

int Engine_Core_PollEvent(Engine_Core_Events* event, Engine_Core_KeyEvent_KeyCode* key_code)
{
    SDL_Event sdl_event;
    int poll = SDL_PollEvent(&sdl_event);

    if (poll == 0)
    {
        return 0;
    }

    if (sdl_event.type == SDL_QUIT)
    {
        *event = ENGINE_QUIT;
    }

    if (sdl_event.type == SDL_KEYDOWN)
    {
        if (sdl_event.key.keysym.sym == SDLK_ESCAPE)
        {
            *event = ENGINE_QUIT;
            *key_code = ENGINE_ESCAPE;
        }
    }

    return 1;
}

void Engine_Core_Delay(Uint32 milliseconds)
{
    SDL_Delay(milliseconds);
}

void Engine_Core_Quit()
{
    SDL_Quit();
}