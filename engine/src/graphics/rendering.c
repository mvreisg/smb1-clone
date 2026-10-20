#include "engine/include/graphics/rendering.h"
#include <stdio.h>

Engine_Renderer* Engine_Rendering_CreateRenderer(Engine_Window* window, Engine_Renderer_InitializationFlags flags)
{
    if (window == NULL)
    {
        return NULL;
    }

    if (window->window == NULL)
    {
        return NULL;
    }

    SDL_RendererFlags sdl_flags = 0;
    if ((flags & ENGINE_RENDERER_ACCELERATED) == ENGINE_RENDERER_ACCELERATED)
    {
        sdl_flags |= SDL_RENDERER_ACCELERATED;
    }

    Engine_Renderer* renderer = (Engine_Renderer*)malloc(sizeof(Engine_Renderer));

    if (renderer == NULL)
    {
        return NULL;
    }

    renderer->renderer = SDL_CreateRenderer(window->window, -1, sdl_flags);

    if (renderer->renderer == NULL)
    {
        printf("Engine_Rendering_CreateRenderer: SDL_CreateRenderer: %s\n", SDL_GetError());
        Engine_Rendering_FreeRendering(renderer);
        return NULL;
    }

    return renderer;
}

void Engine_Rendering_FreeRenderer(Engine_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer->renderer);
    free(renderer);
    renderer = NULL;
}

int Engine_Rendering_SetRendererDrawColor(
    Engine_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    return SDL_SetRenderDrawColor(renderer->renderer, red, green, blue, alpha);
}

int Engine_Rendering_RendererClear(Engine_Renderer* renderer)
{
    return SDL_RenderClear(renderer->renderer);
}

int Engine_Rendering_RendererCopy(Engine_Renderer* renderer, Engine_Texture* texture, Engine_IntRectangle* crop_rectangle, Engine_IntRectangle* actual_rectangle)
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
    return SDL_RenderCopy(renderer->renderer, texture->texture, &sdl_crop_rectangle, &sdl_actual_rectangle);
}

void Engine_Rendering_RendererPresent(Engine_Renderer* renderer)
{
    SDL_RenderPresent(renderer->renderer);
}

Engine_Texture* Engine_Rendering_CreateTexture(Engine_Renderer* renderer_context, Engine_Image* image)
{
    Engine_Texture* texture = (Engine_Texture*)malloc(sizeof(Engine_Texture));

    texture->texture = SDL_CreateTextureFromSurface(renderer_context->renderer, image->surface);

    return texture;
}

void Engine_Rendering_FreeTexture(Engine_Texture* texture)
{
    SDL_DestroyTexture(texture->texture);
    free(texture);
    texture = NULL;
}

Engine_Rendering_Data* Engine_Rendering_CreateRenderingData(Engine_Renderer* renderer, char* image_path, Engine_IntDimension dimensions)
{
    Engine_Rendering_Data* rendering_data = (Engine_Rendering_Data*)malloc(sizeof(Engine_Rendering_Data));
    rendering_data->image = Engine_Image_LoadImage(image_path);
    rendering_data->texture = Engine_Rendering_CreateTexture(renderer, rendering_data->image);
    return rendering_data;
}