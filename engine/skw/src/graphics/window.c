#include "graphics/window.h"

SKW_Window* SKW_Window_CreateWindow(char* title, SKW_IntRectangle rectangle, SKW_WindowFlags flags)
{
    SKW_Window* context = (SKW_Window*)malloc(sizeof(SKW_Window));

    context->flags = flags;
    context->rectangle = rectangle;
    context->title = title;

    Uint32 sdl_flags = 0;
    if ((flags & SKW_WINDOW_VULKAN) == SKW_WINDOW_VULKAN)
    {
        sdl_flags |= SDL_VIDEO_VULKAN;
    }

    context->window = SDL_CreateWindow(title,
                                       rectangle.point.x,
                                       rectangle.point.y,
                                       rectangle.dimension.width,
                                       rectangle.dimension.height,
                                       sdl_flags);

    return context;
}

void SKW_Window_FreeWindow(SKW_Window* window)
{
    SDL_DestroyWindow(window->window);
    free(window);
    window = NULL;
}