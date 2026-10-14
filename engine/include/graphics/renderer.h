#pragma once

#include "graphics/image.h"
#include "graphics/window.h"
#include "math/geometry.h"
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

Engine_Renderer* Engine_Renderer_CreateRenderer(Engine_Window* window_context, Engine_Renderer_InitializationFlags flags);

void Engine_Renderer_FreeRenderer(Engine_Renderer* renderer);

int Engine_Renderer_SetRenderDrawColor(Engine_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

int Engine_Renderer_RenderClear(Engine_Renderer* renderer);

int Engine_Renderer_RenderCopy(Engine_Renderer* renderer, Engine_Texture* texture, Engine_IntRectangle* crop_rectangle, Engine_IntRectangle* actual_rectangle);

void Engine_Renderer_RenderPresent(Engine_Renderer* renderer);

Engine_Texture* Engine_Renderer_CreateTexture(Engine_Renderer* renderer_context, Engine_Image* image);

void Engine_Renderer_FreeTexture(Engine_Texture* texture);