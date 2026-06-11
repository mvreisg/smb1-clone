#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow(
        "Super Mario Bros. 1 Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;
    float TARGET_FPS = 60.0f;
    float FRAME_DELAY = 1000.0f / TARGET_FPS;

    SDL_Surface* surface = IMG_Load("assets/sprites/playable_characters.png");

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));
    sprite->scale = 4;
    sprite->texture = texture;
    sprite->rectangle.dimension.width = 16 * sprite->scale;
    sprite->rectangle.dimension.height = 32 * sprite->scale;

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
            sprite->rectangle.position.y -= 1;
        }
        else if (aPressed && wPressed == false && sPressed == false && dPressed == false)
        {
            sprite->rectangle.position.x -= 1;
        }
        else if (sPressed && wPressed == false && aPressed == false && dPressed == false)
        {
            sprite->rectangle.position.y += 1;
        }
        else if (dPressed && wPressed == false && aPressed == false && sPressed == false)
        {
            sprite->rectangle.position.x += 1;
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