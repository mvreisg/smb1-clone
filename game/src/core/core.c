#include "core/core.h"
#include "entities/entity.h"
#include "game/include/graphics/renderer.h"
#include "graphics/image.h"
#include "graphics/window.h"
#include <stdbool.h>
#include <stdlib.h>

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
    Engine_Renderer* renderer = Engine_Renderer_CreateRenderer(window, ENGINE_RENDERER_ACCELERATED);

    Engine_Image_Initialize(ENGINE_IMAGE_INITIALIZE_PNG);

    Uint32 dimension_scale = 2;
    Engine_IntDimension block_dimension = {.width = 16, .height = 16};

    Game_Rendering_Data* block_rendering_data = Game_Renderer_CreateRenderingData(renderer, "assets/sprites/blocks.png");
    Game_Rendering_Data* mario_rendering_data = Game_Renderer_CreateRenderingData(renderer, "assets/sprites/mario.png");

    Entity* blocks = (Entity*)calloc(10, sizeof(Entity));
    for (int i = 0; i < 10; i++)
    {
        blocks[i].scene_rectangle = (Engine_IntRectangle){
            .point = {
                .x = i * block_dimension.width * dimension_scale,
                .y = 0},
            .dimension = {.width = block_dimension.width * dimension_scale, .height = block_dimension.height * dimension_scale}};
        blocks[i].texture_crop_rectangle = (Engine_IntRectangle){
            .point = {
                .x = 0,
                .y = 0},
            .dimension = {.width = block_dimension.width, .height = block_dimension.height}};
        blocks[i].camera_rectangle = (Engine_IntRectangle){
            .point = {
                .x = 0,
                .y = 0},
            .dimension = {.width = block_dimension.width * dimension_scale, .height = block_dimension.height * dimension_scale}};
    }

    Engine_IntDimension mario_dimension = {.width = 16, .height = 32};

    Entity* mario = (Entity*)malloc(sizeof(Entity));
    mario->scene_rectangle = (Engine_IntRectangle){
        .point = {
            .x = 0,
            .y = 0},
        .dimension = {.width = mario_dimension.width * dimension_scale, .height = mario_dimension.height * dimension_scale}};
    mario->texture_crop_rectangle = (Engine_IntRectangle){
        .point = {
            .x = 0,
            .y = 0},
        .dimension = {.width = mario_dimension.width, .height = mario_dimension.height}};
    mario->camera_rectangle = (Engine_IntRectangle){
        .point = {
            .x = 0,
            .y = 0},
        .dimension = {.width = mario_dimension.width * dimension_scale, .height = mario_dimension.height * dimension_scale}};

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

        Engine_Renderer_RenderClear(renderer);

        for (int i = 0; i < 10; i++)
        {
            blocks[i].camera_rectangle.point.x = blocks[i].scene_rectangle.point.x - camera_rectangle.point.x;
            blocks[i].camera_rectangle.point.y = blocks[i].scene_rectangle.point.y - camera_rectangle.point.y;
            Engine_Renderer_RenderCopy(renderer, block_rendering_data->texture, &blocks[i].texture_crop_rectangle, &blocks[i].camera_rectangle);
        }

        mario->camera_rectangle.point.x = mario->scene_rectangle.point.x - camera_rectangle.point.x;
        mario->camera_rectangle.point.y = mario->scene_rectangle.point.y - camera_rectangle.point.y;
        Engine_Renderer_RenderCopy(renderer, mario_rendering_data->texture, &mario->texture_crop_rectangle, &mario->camera_rectangle);

        Engine_Renderer_RenderPresent(renderer);
        Engine_Core_Delay(FRAME_DELAY);
    }

    Engine_Renderer_FreeTexture(block_rendering_data->texture);
    Engine_Image_Free(block_rendering_data->image);

    Engine_Renderer_FreeTexture(mario_rendering_data->texture);
    Engine_Image_Free(mario_rendering_data->image);

    free(blocks);
    blocks = NULL;

    Engine_Renderer_FreeRenderer(renderer);
    Engine_Window_FreeWindow(window);
    Engine_Core_Quit();

    return 0;
}