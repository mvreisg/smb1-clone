#pragma once

#include "math/geometry.h"
#include <SDL2/SDL.h>

typedef enum
{
    SKW_WINDOW_FULLSCREEN = 1,
    SKW_WINDOW_FULLSCREEN_DESKTOP = 2,
    SKW_WINDOW_OPENGL = 4,
    SKW_WINDOW_VULKAN = 8,
    SKW_WINDOW_METAL = 16,
    SKW_WINDOW_HIDDEN = 32,
    SKW_WINDOW_BORDERLESS = 64,
    SKW_WINDOW_RESIZABLE = 128,
    SKW_WINDOW_MINIMIZED = 256,
    SKW_WINDOW_MAXIMIZED = 512,
    SKW_WINDOW_INPUT_GRABBED = 1024,
    SKW_WINDOW_ALLOW_HIGHDPI = 2048,
} SKW_WindowFlags;

typedef struct
{
    SDL_Window* window;
    SKW_WindowFlags flags;
    SKW_IntRectangle rectangle;
    char* title;
} SKW_Window;

SKW_Window* SKW_Window_CreateWindow(char* title, SKW_IntRectangle rectangle, SKW_WindowFlags flags);

void SKW_Window_FreeWindow(SKW_Window* window);