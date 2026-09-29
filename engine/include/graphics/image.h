#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef enum
{
    ENGINE_IMAGE_INITIALIZE_PNG = 1
} Engine_Image_InitializationFlags;

typedef struct
{
    SDL_Surface* surface;
} Engine_Image;

Engine_Image_InitializationFlags Engine_Image_Initialize(Engine_Image_InitializationFlags flags);