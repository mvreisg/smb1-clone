#pragma once

#include "engine/include/graphics/image.h"
#include "engine/include/graphics/window.h"
#include "engine/include/math/geometry.h"
#include <SDL2/SDL.h>

typedef enum
{
    ENGINE_RENDERER_ACCELERATED = 1
} Engine_Renderer_InitializationFlags;

typedef struct
{
    SDL_Renderer* renderer;
} Engine_Renderer;

typedef struct
{
    SDL_Texture* texture;
} Engine_Texture;

typedef struct
{
    char* name;
    Engine_FloatRectangle rectangle
} Engine_Sprite;

typedef struct
{
    Engine_Image* image;
    Engine_Texture* texture;
} Engine_Rendering_Data;

typedef struct
{
    Engine_Rendering_Data* rendering_data;
    Engine_Sprite* sprites;
} Engine_Spritesheet;

Engine_Renderer* Engine_Rendering_CreateRenderer(Engine_Window* window_context, Engine_Renderer_InitializationFlags flags);

void Engine_Rendering_FreeRenderer(Engine_Renderer* renderer);

int Engine_Rendering_SetRendererDrawColor(Engine_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

int Engine_Rendering_RendererClear(Engine_Renderer* renderer);

int Engine_Rendering_RendererCopy(Engine_Renderer* renderer, Engine_Texture* texture, Engine_IntRectangle* crop_rectangle, Engine_IntRectangle* actual_rectangle);

void Engine_Rendering_RendererPresent(Engine_Renderer* renderer);

Engine_Texture* Engine_Rendering_CreateTexture(Engine_Renderer* renderer_context, Engine_Image* image);

void Engine_Rendering_FreeTexture(Engine_Texture* texture);

Engine_Rendering_Data* Engine_Rendering_CreateRenderingData(Engine_Renderer* renderer, char* image_path, Engine_IntDimension dimensions);