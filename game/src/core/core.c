#include "engine/include/core/core.h"
#include "engine/include/graphics/image.h"
#include "engine/include/graphics/window.h"
#include "game/include/entities/entities.h"
#include <stdbool.h>

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
    Engine_Renderer* renderer = Engine_Rendering_CreateRendering(window, ENGINE_RENDERER_ACCELERATED);

    Engine_Image_Initialize(ENGINE_IMAGE_INITIALIZE_PNG);

    Engine_Rendering_Data* mario_rendering_data = Engine_Rendering_CreateRenderingData(
        renderer,
        "assets/sprites/mario.png",
        (Engine_IntDimension){.width = 16, .height = 32});

    Engine_FloatDimension mario_dimension = {.width = 16, .height = 32};
    Engine_FloatDimension mario_scale = {.width = 1, .height = 1};

    Entity* mario = Game_Entity_Instantiate((Engine_FloatRectangle){
                                                .point = {
                                                    .x = 0,
                                                    .y = 0},
                                                .dimension = mario_dimension},
                                            (Engine_FloatRectangle){.point = {.x = 0, .y = 0}, .dimension = mario_scale});

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
                        mario->scene_rectangle.point.y -= 1;
                        break;
                    case ENGINE_KEYCODE_DOWN:
                        mario->scene_rectangle.point.y += 1;
                        break;
                    case ENGINE_KEYCODE_LEFT:
                        mario->scene_rectangle.point.x -= 1;
                        break;
                    case ENGINE_KEYCODE_RIGHT:
                        mario->scene_rectangle.point.x += 1;
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

        camera_rectangle.point.x = mario->scene_rectangle.point.x - camera_rectangle.dimension.width / 2 + mario->scene_rectangle.dimension.width / 2;
        camera_rectangle.point.y = mario->scene_rectangle.point.y - camera_rectangle.dimension.height / 2 + mario->scene_rectangle.dimension.height / 2;

        Engine_Rendering_RenderClear(renderer);

        Engine_Rendering_RenderCopy(renderer, mario_rendering_data->texture, &mario->texture_crop_rectangle, &mario->camera_rectangle);

        Engine_Rendering_RenderPresent(renderer);
        Engine_Core_Delay(FRAME_DELAY);
    }

    Game_Entity_Free(mario);

    Engine_Rendering_FreeTexture(mario_rendering_data->texture);
    Engine_Image_Free(mario_rendering_data->image);

    Engine_Rendering_FreeRendering(renderer);
    Engine_Window_FreeWindow(window);
    Engine_Core_Quit();

    return 0;
}