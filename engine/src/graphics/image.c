#include "graphics/image.h"

Engine_Image_InitializationFlags Engine_Image_Initialize(Engine_Image_InitializationFlags flags)
{
    IMG_InitFlags sdlFlags = 0;
    switch (flags)
    {
    case ENGINE_IMAGE_INITIALIZE_PNG:
        sdlFlags |= IMG_INIT_PNG;
        break;
    }

    int initializedFlags = IMG_Init(sdlFlags);

    Engine_Image_InitializationFlags returnFlags = 0;
    if ((initializedFlags & IMG_INIT_PNG) == IMG_INIT_PNG)
    {
        returnFlags |= ENGINE_IMAGE_INITIALIZE_PNG;
    }

    return returnFlags;
}

Engine_Image* Engine_Image_LoadImage(char* path)
{
    Engine_Image* image = (Engine_Image*)malloc(sizeof(Engine_Image));

    image->surface = IMG_Load(path);

    return image;
}

void Engine_Image_Free(Engine_Image* image)
{
    SDL_FreeSurface(image->surface);
}