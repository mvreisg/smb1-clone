#include "core/core.h"
#include "graphics/renderer.h"
#include "graphics/window.h"
#include <stdbool.h>
#include <stdio.h>

int Game_Core_Run()
{
    bool running = true;

    Uint32 TARGET_FPS = 60;
    Uint32 FRAME_DELAY = 1000 / TARGET_FPS;

    Engine_Core_InitializationStatus initialization_status =
        Engine_Core_Initialize(ENGINE_INITIALIZE_VIDEO);
    if ((initialization_status & ENGINE_ERROR) == ENGINE_ERROR)
    {
        Engine_Core_Quit();
        return 1;
    }

    Engine_IntRectangle window_rectangle = {.point = {.x = 0, .y = 0},
                                            .dimension = {.width = 1280, .height = 720}};
    Engine_Window* window = Engine_Window_CreateWindow("smb1-clone", window_rectangle, 0);

    if (window == NULL)
    {
        printf("Engine error: Failed to create window.\n");

        Engine_Core_Quit();

        return 1;
    }

    Engine_Renderer* renderer = Engine_Renderer_CreateRenderer(window, ENGINE_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        printf("Engine error: Failed to create renderer.\n");

        Engine_Window_FreeWindow(window);
        Engine_Core_Quit();

        return 1;
    }

    while (running)
    {
        Engine_Core_Events events;
        Engine_Core_KeyEvent_KeyCode key_code;
        while (Engine_Core_PollEvent(&events, &key_code))
        {
            if ((events & ENGINE_QUIT) == ENGINE_QUIT)
            {
                running = false;
                break;
            }
            if ((events & ENGINE_KEY_DOWN) == ENGINE_KEY_DOWN)
            {
                if (key_code == ENGINE_ESCAPE)
                {
                    running = false;
                    break;
                }
            }
        }

        if (running == false)
        {
            break;
        }

        Engine_Renderer_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        Engine_Renderer_RenderClear(renderer);
        Engine_Renderer_RenderPresent(renderer);

        Engine_Core_Delay(FRAME_DELAY);
    }

    Engine_Renderer_FreeRenderer(renderer);
    Engine_Window_FreeWindow(window);
    Engine_Core_Quit();

    return 0;
}