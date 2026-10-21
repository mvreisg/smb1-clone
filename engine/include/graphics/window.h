#pragma once

#include "math/geometry.h"
#include <SDL2/SDL.h>

typedef enum
{
    ENGINE_WINDOW_FULLSCREEN,
    ENGINE_WINDOW_FULLSCREEN_DESKTOP,
    ENGINE_WINDOW_OPENGL,
    ENGINE_WINDOW_VULKAN,
    ENGINE_WINDOW_METAL,
    ENGINE_WINDOW_HIDDEN,
    ENGINE_WINDOW_BORDERLESS,
    ENGINE_WINDOW_RESIZABLE,
    ENGINE_WINDOW_MINIMIZED,
    ENGINE_WINDOW_MAXIMIZED,
    ENGINE_WINDOW_INPUT_GRABBED,
    ENGINE_WINDOW_ALLOW_HIGHDPI,
} Engine_WindowFlags;

typedef struct
{
    SDL_Window* window;
    Engine_WindowFlags flags;
    Engine_IntRectangle rectangle;
    char title[100];
} Engine_Window;

Engine_Window* Engine_CreateWindow(char* title, Engine_IntRectangle rectangle, Engine_WindowFlags flags);

void Engine_FreeWindow(Engine_Window* window);