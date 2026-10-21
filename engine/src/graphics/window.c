#include "graphics/window.h"
#include <string.h>

Engine_Window* Engine_CreateWindow(char* title, Engine_IntRectangle rectangle, Engine_WindowFlags flags)
{
    Engine_Window* window_context = (Engine_Window*)malloc(sizeof(Engine_Window));

    window_context->flags = flags;
    window_context->rectangle = rectangle;
    strcpy(window_context->title, title);

    Uint32 sdl_flags = 0;
    if ((flags & ENGINE_WINDOW_OPENGL) == ENGINE_WINDOW_OPENGL)
    {
        sdl_flags |= SDL_WINDOW_OPENGL;
    }

    window_context->window = SDL_CreateWindow(title, rectangle.point.x, rectangle.point.y, rectangle.dimension.width, rectangle.dimension.height, sdl_flags);

    return window_context;
}

void Engine_Window_FreeWindow(Engine_Window* window)
{
    SDL_DestroyWindow(window->window);

    free(window);
    window = NULL;
}