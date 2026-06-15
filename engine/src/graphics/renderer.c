#include "renderer.h"

Boot_Renderer* Boot_Renderer_CreateRenderer(Boot_Window* window_context,
                                            Boot_Renderer_InitializationFlags flags)
{
    SDL_RendererFlags sdl_flags = 0;
    if ((flags & RENDERER_ACCELERATED) == RENDERER_ACCELERATED)
    {
        sdl_flags |= SDL_RENDERER_ACCELERATED;
    }

    Boot_Renderer* context = (Boot_Renderer*)malloc(sizeof(Boot_Renderer));

    context->renderer = SDL_CreateRenderer(window_context->window, -1, sdl_flags);
}