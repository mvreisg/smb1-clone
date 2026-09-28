#include "graphics/image.h"

SKW_Image_InitializationFlags SKW_Image_Initialize(SKW_Image_InitializationFlags flags)
{
    IMG_InitFlags sdlFlags = 0;
    switch (flags)
    {
    case SKW_IMAGE_INITIALIZE_PNG:
        sdlFlags |= IMG_INIT_PNG;
        break;
    }

    int initializedFlags = IMG_Init(sdlFlags);

    SKW_Image_InitializationFlags returnFlags = 0;
    if ((initializedFlags & IMG_INIT_PNG) == IMG_INIT_PNG)
    {
        returnFlags |= SKW_IMAGE_INITIALIZE_PNG;
    }

    return returnFlags;
}

SKW_Image* SKW_Image_LoadImage(char* path)
{
    SKW_Image* image = (SKW_Image*)malloc(sizeof(SKW_Image));

    image->surface = IMG_Load(path);

    return image;
}

void SKW_Image_Free(SKW_Image* image)
{
    SDL_FreeSurface(image->surface);
}