#include "core/core.h"
#include "graphics/renderer.h"
#include "graphics/window.h"
#include <stdbool.h>

int Game_Core_Run()
{
    bool running = true;

    float TARGET_FPS = 60.0f;
    float FRAME_DELAY = 1000.0f / TARGET_FPS;

    Engine_Core_InitializationStatus initialization_status =
        Engine_Core_Initialize(ENGINE_INITIALIZE_VIDEO);
    if ((initialization_status & ENGINE_ERROR) == ENGINE_ERROR)
    {
        Engine_Core_Quit();
        return 1;
    }

    Engine_IntRectangle window_rectangle = {.point = {.x = 0, .y = 0},
                                            .dimension = {.width = 1280, .height = 720}};
    Engine_Window* window =
        Engine_Window_CreateWindow("smb1-clone", window_rectangle, ENGINE_WINDOW_VULKAN);
    Engine_Renderer* renderer = Engine_Renderer_CreateRenderer(window, ENGINE_RENDERER_ACCELERATED);

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

        Engine_Renderer_RenderClear(renderer);
        Engine_Renderer_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        Engine_Renderer_RenderPresent(renderer);

        Engine_Core_Delay(FRAME_DELAY);
    }

    Engine_Renderer_FreeRenderer(renderer);
    Engine_Window_FreeWindow(window);
    Engine_Core_Quit();

    return 0;
}