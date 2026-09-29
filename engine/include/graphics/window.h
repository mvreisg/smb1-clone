#pragma once

#include "math/geometry.h"
#include <SDL2/SDL.h>

typedef enum
{
    ENGINE_WINDOW_FULLSCREEN = 1,
    ENGINE_WINDOW_FULLSCREEN_DESKTOP = 2,
    ENGINE_WINDOW_OPENGL = 4,
    ENGINE_WINDOW_VULKAN = 8,
    ENGINE_WINDOW_METAL = 16,
    ENGINE_WINDOW_HIDDEN = 32,
    ENGINE_WINDOW_BORDERLESS = 64,
    ENGINE_WINDOW_RESIZABLE = 128,
    ENGINE_WINDOW_MINIMIZED = 256,
    ENGINE_WINDOW_MAXIMIZED = 512,
    ENGINE_WINDOW_INPUT_GRABBED = 1024,
    ENGINE_WINDOW_ALLOW_HIGHDPI = 2048,
} Engine_WindowFlags;

typedef struct
{
    SDL_Window* window;
    Engine_WindowFlags flags;
    Engine_IntRectangle rectangle;
    char* title;
} Engine_Window;

Engine_Window*
Engine_Window_CreateWindow(char* title, Engine_IntRectangle rectangle, Engine_WindowFlags flags);

void Engine_Window_FreeWindow(Engine_Window* window);