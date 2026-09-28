#pragma once

#include "graphics/texture.h"
#include "graphics/window.h"
#include "math/geometry.h"
#include <SDL2/SDL.h>

typedef enum
{
    SKW_RENDERER_ACCELERATED = 1
} SKW_Renderer_InitializationFlags;

typedef struct
{
    SDL_Renderer* renderer;
} SKW_Renderer;

SKW_Renderer* SKW_Renderer_CreateRenderer(SKW_Window* window_context,
                                          SKW_Renderer_InitializationFlags flags);

void SKW_Renderer_FreeRenderer(SKW_Renderer* renderer);

int SKW_Renderer_SetRenderDrawColor(
    SKW_Renderer* renderer, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

int SKW_Renderer_RenderClear(SKW_Renderer* renderer);

int SKW_Renderer_RenderCopy(SKW_Renderer* renderer,
                            SKW_Texture* texture,
                            SKW_IntRectangle* crop_rectangle,
                            SKW_IntRectangle* actual_rectangle);

void SKW_Renderer_RenderPresent(SKW_Renderer* renderer);