#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Super Mario Bros. 1 Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;
    float TARGET_FPS = 60.0f;
    float FRAME_DELAY = 1000.0f / TARGET_FPS;
    int x = 0;
    int y = 0;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
        }

        const Uint8* keyboard = SDL_GetKeyboardState(NULL);
        bool wPressed = keyboard[SDL_SCANCODE_W];
        bool aPressed = keyboard[SDL_SCANCODE_A];
        bool sPressed = keyboard[SDL_SCANCODE_S];
        bool dPressed = keyboard[SDL_SCANCODE_D];

        if (wPressed && aPressed == false && sPressed == false && dPressed == false)
        {
            y--;
        }
        else if (aPressed && wPressed == false && sPressed == false && dPressed == false)
        {
            x--;
        }
        else if (sPressed && wPressed == false && aPressed == false && dPressed == false)
        {
            y++;
        }
        else if (dPressed && wPressed == false && aPressed == false && sPressed == false)
        {
            x++;
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect rect = {x, y, 50, 50};
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);

        SDL_Delay(FRAME_DELAY);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}