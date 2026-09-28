#include "graphics/renderer.h"
#include "graphics/texture.h"

SKW_Renderer* SKW_Renderer_CreateRenderer(SKW_Window* window,
                                          SKW_Renderer_InitializationFlags flags)
{
    SDL_RendererFlags sdl_flags = 0;
    if ((flags & SKW_RENDERER_ACCELERATED) == SKW_RENDERER_ACCELERATED)
    {
        sdl_flags |= SDL_RENDERER_ACCELERATED;
    }

    SKW_Renderer* renderer = (SKW_Renderer*)malloc(sizeof(SKW_Renderer));

    renderer->renderer = SDL_CreateRenderer(window->window, -1, sdl_flags);

    return renderer;
}

void SKW_Renderer_FreeRenderer(SKW_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer->renderer);
    free(renderer);
    renderer = NULL;
}

int SKW_Renderer_SetRenderDrawColor(
    SKW_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    return SDL_SetRenderDrawColor(renderer->renderer, red, green, blue, alpha);
}

int SKW_Renderer_RenderClear(SKW_Renderer* renderer)
{
    return SDL_RenderClear(renderer->renderer);
}

int SKW_Renderer_RenderCopy(SKW_Renderer* renderer,
                            SKW_Texture* texture,
                            SKW_IntRectangle* crop_rectangle,
                            SKW_IntRectangle* actual_rectangle)
{
    SDL_Rect sdl_crop_rectangle = {
        .x = crop_rectangle->point.x,
        .y = crop_rectangle->point.y,
        .w = crop_rectangle->dimension.width,
        .h = crop_rectangle->dimension.height,
    };
    SDL_Rect sdl_actual_rectangle = {
        .x = actual_rectangle->point.x,
        .y = actual_rectangle->point.y,
        .w = actual_rectangle->dimension.width,
        .h = actual_rectangle->dimension.height,
    };
    return SDL_RenderCopy(
        renderer->renderer, texture->texture, &sdl_crop_rectangle, &sdl_actual_rectangle);
}

void SKW_Renderer_RenderPresent(SKW_Renderer* renderer)
{
    SDL_RenderPresent(renderer->renderer);
}