#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef enum
{
    IMAGE_INITIALIZE_PNG = 1
} Boot_Image_InitializationFlags;

typedef struct
{
    SDL_Surface* surface;
} Boot_Image;

Boot_Image_InitializationFlags Boot_Image_Initialize(Boot_Image_InitializationFlags flags);