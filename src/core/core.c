#include "core/core.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>

int Core_Run()
{
    bool running = true;

    Uint32 TARGET_FPS = 60;
    Uint32 FRAME_DELAY = 1000 / TARGET_FPS;

    int initialization_status = SDL_Init(SDL_INIT_VIDEO);
    if (initialization_status)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Rect window_rectangle = {.x = 100, .y = 100, .w = 1280, .h = 720};
    SDL_Rect camera_rectangle = {.x = 0, .y = 0, .w = 1280, .h = 720};

    SDL_Window* window = SDL_CreateWindow("smb1-clone", window_rectangle.x, window_rectangle.y, window_rectangle.w, window_rectangle.h, SDL_WINDOW_VULKAN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    IMG_Init(IMG_INIT_PNG);

    SDL_Texture* mario_texture = IMG_LoadTexture(renderer, "assets/sprites/mario.png");

    SDL_Rect mario_rect = {.x = 0, .y = 0, .w = 16, .h = 32};
    SDL_Rect mario_scale = {.x = 1, .y = 1, .w = 2, .h = 2};

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            mario_rect.y -= 1;
                            break;
                        case SDLK_DOWN:
                            mario_rect.y += 1;
                            break;
                        case SDLK_LEFT:
                            mario_rect.x -= 1;
                            break;
                        case SDLK_RIGHT:
                            mario_rect.x += 1;
                            break;
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }

        if (running == false)
        {
            break;
        }

        camera_rectangle.x = mario_rect.x - camera_rectangle.w / 2 + mario_rect.w / 2;
        camera_rectangle.y = mario_rect.y - camera_rectangle.h / 2 + mario_rect.h / 2;

        SDL_RenderClear(renderer);

        SDL_RenderCopy(
            renderer,
            mario_texture,
            &(SDL_Rect){
                .x = 0,
                .y = 0,
                .w = mario_rect.w,
                .h = mario_rect.h},
            &(SDL_Rect){
                .x = mario_rect.x - camera_rectangle.x,
                .y = mario_rect.y - camera_rectangle.y,
                .w = mario_rect.w * mario_scale.w,
                .h = mario_rect.h * mario_scale.h});

        SDL_RenderCopy(
            renderer,
            mario_texture,
            &(SDL_Rect){
                .x = 0,
                .y = 0,
                .w = mario_rect.w,
                .h = mario_rect.h},
            &(SDL_Rect){
                .x = 100 - camera_rectangle.x,
                .y = 100 - camera_rectangle.y,
                .w = mario_rect.w * mario_scale.w,
                .h = mario_rect.h * mario_scale.h});

        SDL_RenderPresent(renderer);

        SDL_Delay(FRAME_DELAY);
    }

    SDL_DestroyTexture(mario_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}