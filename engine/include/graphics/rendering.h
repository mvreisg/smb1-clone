#include "geometry.h"
#include "window.h"
#include <SDL2/SDL.h>

typedef enum
{
    RENDERER_ACCELERATED = 1
} RendererInitializationFlags;

typedef struct
{
    SDL_Renderer* renderer;
} RenderingContext;

typedef struct
{
    int scale;
    FloatRectangle rectangle;
    SDL_Texture* texture;
} Sprite;

RenderingContext* Boot_Rendering_CreateRenderer(WindowContext* window_context,
                                                RendererInitializationFlags flags)
{
    SDL_RendererFlags sdl_flags = 0;
    if ((flags & RENDERER_ACCELERATED) == RENDERER_ACCELERATED)
    {
        sdl_flags |= SDL_RENDERER_ACCELERATED;
    }

    RenderingContext* context = (RenderingContext*)malloc(sizeof(RenderingContext));

    context->renderer = SDL_CreateRenderer(window_context->window, -1, sdl_flags);
}