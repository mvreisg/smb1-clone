#include "core.h"

InitializationStatus Boot_Main_Initialize(InitializationFlags flags)
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