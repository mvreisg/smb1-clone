#include "graphics/renderer.h"
#include "graphics/texture.h"

Engine_Renderer* Engine_Renderer_CreateRenderer(Engine_Window* window,
                                                Engine_Renderer_InitializationFlags flags)
{
    SDL_RendererFlags sdl_flags = 0;
    if ((flags & ENGINE_RENDERER_ACCELERATED) == ENGINE_RENDERER_ACCELERATED)
    {
        sdl_flags |= SDL_RENDERER_ACCELERATED;
    }

    Engine_Renderer* renderer = (Engine_Renderer*)malloc(sizeof(Engine_Renderer));

    renderer->renderer = SDL_CreateRenderer(window->window, -1, sdl_flags);

    return renderer;
}

void Engine_Renderer_FreeRenderer(Engine_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer->renderer);
    free(renderer);
    renderer = NULL;
}

int Engine_Renderer_SetRenderDrawColor(
    Engine_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    return SDL_SetRenderDrawColor(renderer->renderer, red, green, blue, alpha);
}

int Engine_Renderer_RenderClear(Engine_Renderer* renderer)
{
    return SDL_RenderClear(renderer->renderer);
}

int Engine_Renderer_RenderCopy(Engine_Renderer* renderer,
                               Engine_Texture* texture,
                               Engine_IntRectangle* crop_rectangle,
                               Engine_IntRectangle* actual_rectangle)
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

void Engine_Renderer_RenderPresent(Engine_Renderer* renderer)
{
    SDL_RenderPresent(renderer->renderer);
}