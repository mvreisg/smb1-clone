#include "geometry.h"
#include "window.h"
#include <SDL2/SDL.h>

typedef enum
{
    RENDERER_ACCELERATED = 1
} Boot_Renderer_InitializationFlags;

typedef struct
{
    SDL_Renderer* renderer;
} Boot_Renderer;

Boot_Renderer* Boot_Renderer_CreateRenderer(Boot_Window* window_context,
                                            Boot_Renderer_InitializationFlags flags);