#pragma once
#include "camera/camera.h"
#include "entity/entity.h"
#include "image/image.h"


typedef struct
{
    Entity* mario;
    Entity* blocks;
} Stage;

Stage* Stage_Create();

void Stage_Tick(Stage* stage, Camera* camera, const Uint8* keystate);

void Stage_Render(Stage* stage, Camera* camera, SDL_Renderer* renderer, Textures* textures);

void Stage_Free(Stage* stage);