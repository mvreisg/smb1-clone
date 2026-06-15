#include "window.h"

WindowContext* Boot_Window_CreateWindow(char* title, IntRectangle rectangle, WindowFlags flags)
{
    WindowContext* context = (WindowContext*)malloc(sizeof(WindowContext));

    context->flags = flags;
    context->rectangle = rectangle;
    context->title = title;

    Uint32 sdl_flags = 0;
    if ((flags & WINDOW_VULKAN) == WINDOW_VULKAN)
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