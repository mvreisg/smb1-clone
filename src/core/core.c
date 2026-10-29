#include "core/core.h"
#include "camera/camera.h"
#include "stage/stage.h"
#include <SDL.h>
#include <stdbool.h>

int Core_Run()
{
    bool running = true;

    const Uint32 TARGET_FPS = 60;
    const Uint32 FRAME_DELAY_INT = 1000 / TARGET_FPS;
    const float FRAME_DELAY_FLOAT = 1000 / TARGET_FPS;
    const float FRAME_DELAY_DIFF = FRAME_DELAY_FLOAT - FRAME_DELAY_INT;
    float accumulated_frame_delay;

    SDL_Rect window_rect = {.x = 100, .y = 100, .w = 1280, .h = 720};

    SDL_Window* window = SDL_CreateWindow("smb1-clone", window_rect.x, window_rect.y, window_rect.w, window_rect.h, SDL_WINDOW_VULKAN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int img_init_status = Image_Init();
    if (img_init_status)
    {
        SDL_Quit();
        return 1;
    }

    Textures* textures = Image_Create(renderer);

    Camera* camera = Camera_Create((SDL_FRect){.x = 0, .y = 0, .w = 1280, .h = 720});
    Stage* stage = Stage_Create();

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
                            break;
                        case SDLK_DOWN:
                            break;
                        case SDLK_LEFT:
                            break;
                        case SDLK_RIGHT:
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

        const Uint8* keystate = SDL_GetKeyboardState(NULL);

        Stage_Tick(stage, camera, keystate);

        SDL_RenderClear(renderer);

        Stage_Render(stage, camera, renderer, textures);

        SDL_RenderPresent(renderer);

        SDL_Delay(FRAME_DELAY_INT);
        accumulated_frame_delay += FRAME_DELAY_DIFF;
        if (accumulated_frame_delay >= 1.0)
        {
            accumulated_frame_delay -= 1.0;
            SDL_Delay(1);
        }
    }

    Camera_Free(camera);
    Stage_Free(stage);
    Image_Free(textures);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}