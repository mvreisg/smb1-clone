#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef enum
{
    IMAGE_INITIALIZE_PNG = 1
} ImageInitalizationFlags;

ImageInitalizationFlags Boot_Rendering_Initialize(ImageInitalizationFlags flags);