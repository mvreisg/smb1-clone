#include "stage/stage.h"
#include "entity/entity.h"
#include <stdlib.h>

const SDL_Rect WORLD_SCALE = {.x = 1, .y = 1, .w = 2, .h = 2};

Stage* Stage_Create()
{
    Stage* stage = (Stage*)malloc(sizeof(Stage));
    stage->mario = Entity_Create(1);
    stage->mario->rect = (SDL_FRect){
        .x = 0,
        .y = 0,
        .w = 16 * WORLD_SCALE.w,
        .h = 32 * WORLD_SCALE.h};

    stage->blocks = Entity_Create(10);
    for (int i = 0; i < 10; i++)
    {
        stage->blocks[i].rect = (SDL_FRect){
            .x = 0 + 16 * i * WORLD_SCALE.w,
            .y = 0,
            .w = 16 * WORLD_SCALE.w,
            .h = 16 * WORLD_SCALE.h};
    }

    return stage;
}

void Stage_Tick(Stage* stage, Camera* camera, const Uint8* keystate)
{
    if (keystate[SDL_SCANCODE_W])
    {
        stage->mario->rect.y -= 5;
    }
    else if (keystate[SDL_SCANCODE_S])
    {
        stage->mario->rect.y += 5;
    }
    else if (keystate[SDL_SCANCODE_A])
    {
        stage->mario->rect.x -= 5;
    }
    else if (keystate[SDL_SCANCODE_D])
    {
        stage->mario->rect.x += 5;
    }

    camera->rect.x = stage->mario->rect.x - camera->rect.w / 2 + stage->mario->rect.w / 2;
    camera->rect.y = stage->mario->rect.y - camera->rect.h / 2 + stage->mario->rect.h / 2;
}

void Stage_Render(Stage* stage, Camera* camera, SDL_Renderer* renderer, Textures* textures)
{
    for (int i = 0; i < 10; i++)
    {
        SDL_RenderCopy(
            renderer,
            textures->blocks_texture,
            &(SDL_Rect){
                .x = 0,
                .y = 0,
                .w = 16,
                .h = 16},
            &(SDL_Rect){
                .x = stage->blocks[i].rect.x - camera->rect.x,
                .y = stage->blocks[i].rect.y - camera->rect.y,
                .w = stage->blocks[i].rect.w,
                .h = stage->blocks[i].rect.h});
    }

    SDL_RenderCopy(
        renderer,
        textures->mario_texture,
        &(SDL_Rect){
            .x = 0,
            .y = 0,
            .w = 16,
            .h = 32},
        &(SDL_Rect){
            .x = stage->mario->rect.x - camera->rect.x,
            .y = stage->mario->rect.y - camera->rect.y,
            .w = stage->mario->rect.w,
            .h = stage->mario->rect.h});
}

void Stage_Free(Stage* stage)
{
    Entity_Free(stage->blocks);
    Entity_Free(stage->mario);

    free(stage);
    stage = NULL;
}