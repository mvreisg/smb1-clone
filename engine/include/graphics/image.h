#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef enum
{
    SKW_IMAGE_INITIALIZE_PNG = 1
} SKW_Image_InitializationFlags;

typedef struct
{
    SDL_Surface* surface;
} SKW_Image;

SKW_Image_InitializationFlags SKW_Image_Initialize(SKW_Image_InitializationFlags flags);