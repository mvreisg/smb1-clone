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
        return poll;
    }

    switch (sdl_event.type)
    {
        case SDL_QUIT:
            *event = ENGINE_QUIT;
            break;
        case SDL_KEYDOWN:
            switch (sdl_event.key.keysym.sym)
            {
                case SDLK_UP:
                    *event = ENGINE_KEY_DOWN;
                    *key_code = ENGINE_KEYCODE_UP;
                    break;
                case SDLK_DOWN:
                    *event = ENGINE_KEY_DOWN;
                    *key_code = ENGINE_KEYCODE_DOWN;
                    break;
                case SDLK_LEFT:
                    *event = ENGINE_KEY_DOWN;
                    *key_code = ENGINE_KEYCODE_LEFT;
                    break;
                case SDLK_RIGHT:
                    *event = ENGINE_KEY_DOWN;
                    *key_code = ENGINE_KEYCODE_RIGHT;
                    break;
                case SDLK_ESCAPE:
                    *event = ENGINE_QUIT;
                    *key_code = ENGINE_KEYCODE_ESCAPE;
                    break;
            }
    }
    return poll;
}

void Engine_Core_Delay(Uint32 milliseconds)
{
    SDL_Delay(milliseconds);
}

void Engine_Core_Quit()
{
    SDL_Quit();
}