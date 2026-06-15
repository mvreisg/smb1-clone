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
} Boot_WindowFlags;

typedef struct
{
    SDL_Window* window;
    Boot_WindowFlags flags;
    Boot_IntRectangle rectangle;
    char* title;
} Boot_Window;

Boot_Window*
Boot_Window_CreateWindow(char* title, Boot_IntRectangle rectangle, Boot_WindowFlags flags);