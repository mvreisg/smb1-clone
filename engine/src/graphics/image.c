#include "image.h"

ImageInitalizationFlags Boot_Rendering_Initialize(ImageInitalizationFlags flags)
{
    IMG_InitFlags sdlFlags = 0;
    switch (flags)
    {
    case IMAGE_INITIALIZE_PNG:
        sdlFlags |= IMG_INIT_PNG;
        break;
    }

    int initializedFlags = IMG_Init(sdlFlags);

    ImageInitalizationFlags returnFlags = 0;
    if ((initializedFlags & IMG_INIT_PNG) == IMG_INIT_PNG)
    {
        returnFlags |= IMAGE_INITIALIZE_PNG;
    }

    return returnFlags;
}