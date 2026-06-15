#include "geometry.h"
#include <SDL2/SDL.h>

typedef enum
{
    WINDOW_FULLSCREEN = 1,
    WINDOW_FULLSCREEN_DESKTOP = 2,
    WINDOW_OPENGL = 4,
    WINDOW_VULKAN = 8,
    WINDOW_METAL = 16,
    WINDOW_HIDDEN = 32,
    WINDOW_BORDERLESS = 64,
    WINDOW_RESIZABLE = 128,
    WINDOW_MINIMIZED = 256,
    WINDOW_MAXIMIZED = 512,
    WINDOW_INPUT_GRABBED = 1024,
    WINDOW_ALLOW_HIGHDPI = 2048,
} WindowFlags;

typedef struct
{
    SDL_Window* window;
    WindowFlags flags;
    IntRectangle rectangle;
    char* title;
} WindowContext;

WindowContext* Boot_Window_CreateWindow(char* title, IntRectangle rectangle, WindowFlags flags);