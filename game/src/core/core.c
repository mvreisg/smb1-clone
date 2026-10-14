#include "core/core.h"
#include "graphics/image.h"
#include "graphics/renderer.h"
#include "graphics/window.h"
#include <stdbool.h>
#include <stdio.h>

int Game_Core_Run()
{
    bool running = true;

    Uint32 TARGET_FPS = 60;
    Uint32 FRAME_DELAY = 1000 / TARGET_FPS;

    Engine_Core_InitializationStatus initialization_status = Engine_Core_Initialize(ENGINE_INITIALIZE_VIDEO);
    if ((initialization_status & ENGINE_ERROR) == ENGINE_ERROR)
    {
        Engine_Core_Quit();
        return 1;
    }

    Engine_IntRectangle window_rectangle = {.point = {.x = 100, .y = 100}, .dimension = {.width = 1280, .height = 720}};
    Engine_IntRectangle camera_rectangle = {.point = {.x = 0, .y = 0}, .dimension = {.width = 1280, .height = 720}};
    Engine_Window* window = Engine_Window_CreateWindow("smb1-clone", window_rectangle, 0);

    if (window == NULL)
    {
        printf("Game_Core_Run: Engine_Window_CreateWindow: Failed to create window.\n");

        Engine_Core_Quit();

        return 1;
    }

    Engine_Renderer* renderer = Engine_Renderer_CreateRenderer(window, ENGINE_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        printf("Game_Core_Run: Engine_Renderer_CreateRenderer: Failed to create renderer.\n");

        Engine_Window_FreeWindow(window);
        Engine_Core_Quit();

        return 1;
    }

    Engine_Image_Initialize(ENGINE_IMAGE_INITIALIZE_PNG);
    Engine_Image* blocks_image = Engine_Image_LoadImage("assets/sprites/blocks.png");
    Engine_Texture* blocks_texture = Engine_Renderer_CreateTexture(renderer, blocks_image);
    Engine_IntRectangle blocks_crop_rectangle = {.point = {.x = 0, .y = 0}, .dimension = {.width = 16, .height = 16}};
    Engine_IntRectangle blocks_world_rectangle = {.point = {.x = 0, .y = 0}, .dimension = {.width = 16, .height = 16}};

    while (running)
    {
        Engine_Core_Events events = 0;
        Engine_Core_KeyEvent_KeyCode key_code = 0;
        while (Engine_Core_PollEvent(&events, &key_code))
        {
            if ((events & ENGINE_QUIT) == ENGINE_QUIT)
            {
                running = false;
                break;
            }
            if ((events & ENGINE_KEY_DOWN) == ENGINE_KEY_DOWN)
            {
                switch (key_code)
                {
                    case ENGINE_KEYCODE_UP:
                        camera_rectangle.point.y -= 1;
                        break;
                    case ENGINE_KEYCODE_DOWN:
                        camera_rectangle.point.y += 1;
                        break;
                    case ENGINE_KEYCODE_LEFT:
                        camera_rectangle.point.x -= 1;
                        break;
                    case ENGINE_KEYCODE_RIGHT:
                        camera_rectangle.point.x += 1;
                        break;
                    case ENGINE_KEYCODE_ESCAPE:
                        running = false;
                        break;
                    default:
                        break;
                }
            }
        }

        if (running == false)
        {
            break;
        }

        blocks_world_rectangle.point.x = camera_rectangle.point.x * -1;
        blocks_world_rectangle.point.y = camera_rectangle.point.y * -1;

        Engine_Renderer_RenderClear(renderer);
        Engine_Renderer_RenderCopy(renderer, blocks_texture, &blocks_crop_rectangle, &blocks_world_rectangle);
        Engine_Renderer_RenderPresent(renderer);

        Engine_Core_Delay(FRAME_DELAY);
    }

    Engine_Renderer_FreeTexture(blocks_texture);
    Engine_Image_Free(blocks_image);

    Engine_Renderer_FreeRenderer(renderer);
    Engine_Window_FreeWindow(window);
    Engine_Core_Quit();

    return 0;
}