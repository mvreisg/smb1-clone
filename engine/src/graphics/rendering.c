#include "graphics/rendering.h"
#include <string.h>

Engine_ImageInitializationFlags Engine_InitializeImages(Engine_ImageInitializationFlags flags)
{
    IMG_InitFlags sdlFlags = 0;
    switch (flags)
    {
        case ENGINE_IMAGE_INITIALIZE_PNG:
            sdlFlags |= IMG_INIT_PNG;
            break;
    }

    int initializedFlags = IMG_Init(sdlFlags);

    Engine_ImageInitializationFlags returnFlags = 0;
    if ((initializedFlags & IMG_INIT_PNG) == IMG_INIT_PNG)
    {
        returnFlags |= ENGINE_IMAGE_INITIALIZE_PNG;
    }

    return returnFlags;
}

Engine_Image* Engine_LoadImage(char* path)
{
    Engine_Image* image = (Engine_Image*)malloc(sizeof(Engine_Image));

    image->surface = IMG_Load(path);

    return image;
}

void Engine_FreeImage(Engine_Image* image)
{
    SDL_FreeSurface(image->surface);

    free(image);
    image = NULL;
}

Engine_Renderer* Engine_CreateRenderer(Engine_Window* window, Engine_RendererInitializationFlags flags)
{
    SDL_RendererFlags sdl_flags = 0;
    if ((flags & ENGINE_RENDERER_INITIALIZE_ACCELERATED) == ENGINE_RENDERER_INITIALIZE_ACCELERATED)
    {
        sdl_flags |= SDL_RENDERER_ACCELERATED;
    }

    Engine_Renderer* renderer = (Engine_Renderer*)malloc(sizeof(Engine_Renderer));
    renderer->renderer = SDL_CreateRenderer(window->window, -1, sdl_flags);
    return renderer;
}

void Engine_Rendering_FreeRenderer(Engine_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer->renderer);

    free(renderer);
    renderer = NULL;
}

int Engine_ClearRenderer(Engine_Renderer* renderer)
{
    return SDL_RenderClear(renderer->renderer);
}

int Engine_CopyTextureToRenderer(Engine_Renderer* renderer, Engine_Texture* texture, Engine_IntRectangle* crop_rectangle, Engine_IntRectangle* actual_rectangle)
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

void Engine_PresentRenderer(Engine_Renderer* renderer)
{
    SDL_RenderPresent(renderer->renderer);
}

Engine_Texture* Engine_CreateTexture(Engine_Renderer* renderer_context, Engine_Image* image)
{
    Engine_Texture* texture = (Engine_Texture*)malloc(sizeof(Engine_Texture));
    texture->texture = SDL_CreateTextureFromSurface(renderer_context->renderer, image->surface);
    return texture;
}

void Engine_FreeTexture(Engine_Texture* texture)
{
    SDL_DestroyTexture(texture->texture);

    free(texture);
    texture = NULL;
}

Engine_Rendering_Data* Engine_CreateRenderingData(Engine_Renderer* renderer, char* image_path)
{
    Engine_Rendering_Data* rendering_data = (Engine_Rendering_Data*)malloc(sizeof(Engine_Rendering_Data));
    rendering_data->image = Engine_Image_LoadImage(image_path);
    rendering_data->texture = Engine_Rendering_CreateTexture(renderer, rendering_data->image);
    return rendering_data;
}

void Engine_FreeRenderingData(Engine_Rendering_Data* rendering_data)
{
    Engine_FreeImage(rendering_data->image);
    Engine_FreeTexture(rendering_data->texture);

    free(rendering_data);
    rendering_data = NULL;
}

Engine_Sprite* Engine_Rendering_CreateSprite(char* name, Engine_IntRectangle rectangle)
{
    Engine_Sprite* sprite = (Engine_Sprite*)malloc(sizeof(Engine_Sprite));
    strcpy(sprite->name, name);
    sprite->rectangle = rectangle;
    return sprite;
}

void Engine_Rendering_FreeSprite(Engine_Sprite* sprite)
{
    free(sprite);
    sprite = NULL;
}