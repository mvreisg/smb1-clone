#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    bool running = true;

    float TARGET_FPS = 60.0f;
    float FRAME_DELAY = 1000.0f / TARGET_FPS;

    while (running)
    {

        if (wPressed && aPressed == false && sPressed == false && dPressed == false)
        {
        }
        else if (aPressed && wPressed == false && sPressed == false && dPressed == false)
        {
        }
        else if (sPressed && wPressed == false && aPressed == false && dPressed == false)
        {
        }
        else if (dPressed && wPressed == false && aPressed == false && sPressed == false)
        {
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_Rect cropRect = {.x = 0, .y = 0, .w = 16, .h = 32};

        SDL_Rect rect = {.x = sprite->rectangle.position.x,
                         .y = sprite->rectangle.position.y,
                         .w = sprite->rectangle.dimension.width,
                         .h = sprite->rectangle.dimension.height};
        SDL_RenderCopy(renderer, sprite->texture, &cropRect, &rect);

        SDL_RenderPresent(renderer);

        SDL_Delay(FRAME_DELAY);
    }

    free(sprite);
    sprite = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}