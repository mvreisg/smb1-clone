#include "core/core.h"
#include "entities/entities.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>

int Core_Run()
{
    bool running = true;

    const Uint32 TARGET_FPS = 60;
    const Uint32 FRAME_DELAY_INT = 1000 / TARGET_FPS;
    const float FRAME_DELAY_FLOAT = 1000 / TARGET_FPS;
    float accumulated_frame_delay;

    int initialization_status = SDL_Init(SDL_INIT_VIDEO);
    if (initialization_status)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Rect window_rect = {.x = 100, .y = 100, .w = 1280, .h = 720};
    SDL_Rect camera_rect = {.x = 0, .y = 0, .w = 1280, .h = 720};

    SDL_Window* window = SDL_CreateWindow("smb1-clone", window_rect.x, window_rect.y, window_rect.w, window_rect.h, SDL_WINDOW_VULKAN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    IMG_Init(IMG_INIT_PNG);

    SDL_Texture* mario_texture = IMG_LoadTexture(renderer, "assets/sprites/mario.png");
    SDL_Texture* block_texture = IMG_LoadTexture(renderer, "assets/sprites/blocks.png");

    SDL_Rect scale = {.x = 1, .y = 1, .w = 2, .h = 2};

    Entity* mario = Entity_Create(1);
    mario->rect = (SDL_FRect){.x = 0, .y = 0, .w = 16 * scale.w, .h = 32 * scale.h};

    Entity* blocks = Entity_Create(10);
    for (int i = 0; i < 10; i++)
    {
        blocks[i].rect = (SDL_FRect){.x = 0 + 16 * i * scale.w, .y = 0, .w = 16 * scale.w, .h = 16 * scale.h};
    }

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
                            mario->rect.y -= 1;
                            break;
                        case SDLK_DOWN:
                            mario->rect.y += 1;
                            break;
                        case SDLK_LEFT:
                            mario->rect.x -= 1;
                            break;
                        case SDLK_RIGHT:
                            mario->rect.x += 1;
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

        camera_rect.x = mario->rect.x - camera_rect.w / 2 + mario->rect.w / 2;
        camera_rect.y = mario->rect.y - camera_rect.h / 2 + mario->rect.h / 2;

        SDL_RenderClear(renderer);

        for (int i = 0; i < 10; i++)
        {
            SDL_RenderCopy(
                renderer,
                block_texture,
                &(SDL_Rect){
                    .x = 0,
                    .y = 0,
                    .w = 16,
                    .h = 16},
                &(SDL_Rect){
                    .x = blocks[i].rect.x - camera_rect.x,
                    .y = blocks[i].rect.y - camera_rect.y,
                    .w = blocks[i].rect.w,
                    .h = blocks[i].rect.h});
        }

        SDL_RenderCopy(
            renderer,
            mario_texture,
            &(SDL_Rect){
                .x = 0,
                .y = 0,
                .w = 16,
                .h = 32},
            &(SDL_Rect){
                .x = mario->rect.x - camera_rect.x,
                .y = mario->rect.y - camera_rect.y,
                .w = mario->rect.w,
                .h = mario->rect.h});

        SDL_RenderPresent(renderer);

        SDL_Delay(FRAME_DELAY_INT);
        accumulated_frame_delay = FRAME_DELAY_FLOAT - FRAME_DELAY_INT;
        if (accumulated_frame_delay >= 1.0)
        {
            accumulated_frame_delay -= 1.0;
            SDL_Delay(1);
        }
    }

    Entity_Free(blocks);
    Entity_Free(mario);

    SDL_DestroyTexture(mario_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}