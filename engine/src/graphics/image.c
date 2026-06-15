#include "image.h"

Boot_Image_InitializationFlags Boot_Image_Initialize(Boot_Image_InitializationFlags flags)
{
    IMG_InitFlags sdlFlags = 0;
    switch (flags)
    {
    case IMAGE_INITIALIZE_PNG:
        sdlFlags |= IMG_INIT_PNG;
        break;
    }

    int initializedFlags = IMG_Init(sdlFlags);

    Boot_Image_InitializationFlags returnFlags = 0;
    if ((initializedFlags & IMG_INIT_PNG) == IMG_INIT_PNG)
    {
        returnFlags |= IMAGE_INITIALIZE_PNG;
    }

    return returnFlags;
}

Boot_Image* Boot_Image_LoadImage(char* path)
{
    Boot_Image* image = (Boot_Image*)malloc(sizeof(Boot_Image));

    image->surface = IMG_Load("assets/sprites/playable_characters.png");

    return image;
}

void Boot_Image_Free(Boot_Image* image)
{
    SDL_FreeSurface(image->surface);
}