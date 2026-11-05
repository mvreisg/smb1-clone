#include "stage/stage.h"
#include "entity/entity.h"
#include <stdlib.h>
#include <string.h>

const SDL_Rect WORLD_SCALE = {.x = 1, .y = 1, .w = 2, .h = 2};

Stage* Stage_Create()
{
    Stage* stage = malloc(sizeof(Stage));

    Entity* mario = Entity_Create("P1_Mario", (SDL_FRect){.x = 0, .y = 0, .w = 16 * WORLD_SCALE.w, .h = 32 * WORLD_SCALE.h});

    stage->character_count = 1;
    stage->characters = Entity_Allocate(stage->character_count);
    for (size_t i = 0; i < stage->character_count; i++)
    {
        stage->characters[i] = mario;
    }

    stage->block_count = 10;
    stage->blocks = Entity_Allocate(stage->block_count);
    for (size_t i = 0; i < stage->block_count; i++)
    {
        char name[100];
        snprintf(name, sizeof(name), "CPU_Block_%zu", i);
        stage->blocks[i] = Entity_Create(name, (SDL_FRect){.x = i * 16 * WORLD_SCALE.w, .y = 0, .w = 16 * WORLD_SCALE.w, .h = 16 * WORLD_SCALE.h});
    }

    return stage;
}

void Stage_Tick(Stage* stage, Camera* camera, const Uint8* keyboard_state)
{
    Entity* player = NULL;
    for (size_t i = 0; i < stage->character_count; i++)
    {
        Entity* character = stage->characters[i];
        if (strcmp(character->name, "P1_Mario") == 0)
        {
            player = character;
            if (keyboard_state[SDL_SCANCODE_W])
            {
                character->rect.y -= 5;
            }
            else if (keyboard_state[SDL_SCANCODE_S])
            {
                character->rect.y += 5;
            }
            else if (keyboard_state[SDL_SCANCODE_A])
            {
                character->rect.x -= 5;
            }
            else if (keyboard_state[SDL_SCANCODE_D])
            {
                character->rect.x += 5;
            }
        }
    }

    if (player == NULL)
        return;

    camera->rect.x = player->rect.x - camera->rect.w / 2 + player->rect.w / 2;
    camera->rect.y = player->rect.y - camera->rect.h / 2 + player->rect.h / 2;
}

void Stage_Render(Stage* stage, Camera* camera, SDL_Renderer* renderer, Textures* textures)
{
    for (size_t i = 0; i < stage->block_count; i++)
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
                .x = stage->blocks[i]->rect.x - camera->rect.x,
                .y = stage->blocks[i]->rect.y - camera->rect.y,
                .w = stage->blocks[i]->rect.w,
                .h = stage->blocks[i]->rect.h});
    }

    for (size_t i = 0; i < stage->character_count; i++)
    {
        SDL_RenderCopy(
            renderer,
            textures->mario_texture,
            &(SDL_Rect){
                .x = 0,
                .y = 0,
                .w = 16,
                .h = 32},
            &(SDL_Rect){
                .x = stage->characters[i]->rect.x - camera->rect.x,
                .y = stage->characters[i]->rect.y - camera->rect.y,
                .w = stage->characters[i]->rect.w,
                .h = stage->characters[i]->rect.h});
    }
}

void Stage_Free(Stage* stage)
{
    Entity_Deallocate(stage->blocks);
    Entity_Deallocate(stage->characters);

    free(stage);
    stage = NULL;
}