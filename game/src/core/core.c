#include "core/core.h"
#include "graphics/image.h"
#include "graphics/renderer.h"
#include "graphics/window.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    Engine_Image* image;
    Engine_Texture* texture;
} Entity_Block_Rendering_Data;

typedef struct
{
    Engine_IntRectangle texture_crop_rectangle;
    Engine_IntRectangle scene_rectangle;
    Engine_IntRectangle camera_rectangle;
} Entity_Block;

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

    Entity_Block_Rendering_Data* engine_block_rendering_data = (Entity_Block_Rendering_Data*)malloc(sizeof(Entity_Block_Rendering_Data));
    engine_block_rendering_data->image = Engine_Image_LoadImage("assets/sprites/blocks.png");
    engine_block_rendering_data->texture = Engine_Renderer_CreateTexture(renderer, engine_block_rendering_data->image);

    Entity_Block* blocks = (Entity_Block*)calloc(10, sizeof(Entity_Block));
    for (int i = 0; i < 10; i++)
    {
        Uint32 width = 16;
        Uint32 height = 16;
        Uint32 scale = 2;
        blocks[i].scene_rectangle = (Engine_IntRectangle){.point = {.x = i * width * scale, .y = 0}, .dimension = {.width = width * scale, .height = height * scale}};
        blocks[i].texture_crop_rectangle = (Engine_IntRectangle){.point = {.x = 0, .y = 0}, .dimension = {.width = width, .height = height}};
        blocks[i].camera_rectangle = (Engine_IntRectangle){.point = {.x = 0, .y = 0}, .dimension = {.width = width * scale, .height = height * scale}};
    }

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

        Engine_Renderer_RenderClear(renderer);

        for (int i = 0; i < 10; i++)
        {
            blocks[i].camera_rectangle.point.x = blocks[i].scene_rectangle.point.x - camera_rectangle.point.x;
            blocks[i].camera_rectangle.point.y = blocks[i].scene_rectangle.point.y - camera_rectangle.point.y;
            Engine_Renderer_RenderCopy(renderer, engine_block_rendering_data->texture, &blocks[i].texture_crop_rectangle, &blocks[i].camera_rectangle);
        }

        Engine_Renderer_RenderPresent(renderer);
        Engine_Core_Delay(FRAME_DELAY);
    }

    Engine_Renderer_FreeTexture(engine_block_rendering_data->texture);
    Engine_Image_Free(engine_block_rendering_data->image);

    free(blocks);
    blocks = NULL;

    Engine_Renderer_FreeRenderer(renderer);
    Engine_Window_FreeWindow(window);
    Engine_Core_Quit();

    return 0;
}