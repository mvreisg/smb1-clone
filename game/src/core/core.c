#include "core/core.h"
#include "graphics/renderer.h"
#include "graphics/window.h"
#include <stdbool.h>

int SMBOneClone_Core_Run()
{
    bool running = true;

    float TARGET_FPS = 60.0f;
    float FRAME_DELAY = 1000.0f / TARGET_FPS;

    SKW_Core_InitializationStatus initialization_status = SKW_Core_Initialize(SKW_INITIALIZE_VIDEO);
    if ((initialization_status & SKW_ERROR) == SKW_ERROR)
    {
        SKW_Core_Quit();
        return 1;
    }

    SKW_IntRectangle window_rectangle = {.point = {.x = 0, .y = 0},
                                         .dimension = {.width = 1280, .height = 720}};
    SKW_Window* window = SKW_Window_CreateWindow("smb1-clone", window_rectangle, 0);
    SKW_Renderer* renderer = SKW_Renderer_CreateRenderer(window, SKW_RENDERER_ACCELERATED);

    while (running)
    {
        SKW_Core_Events events;
        SKW_Core_KeyEvent_KeyCode key_code;
        while (SKW_Core_PollEvent(&events, &key_code))
        {
            if ((events & SKW_QUIT) == SKW_QUIT)
            {
                running = false;
                break;
            }
            if ((events & SKW_KEY_DOWN) == SKW_KEY_DOWN)
            {
                if (key_code == SKW_ESCAPE)
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

        SKW_Renderer_RenderClear(renderer);
        SKW_Renderer_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SKW_Renderer_RenderPresent(renderer);

        SKW_Core_Delay(FRAME_DELAY);
    }

    SKW_Renderer_FreeRenderer(renderer);
    SKW_Window_FreeWindow(window);
    SKW_Core_Quit();

    return 0;
}