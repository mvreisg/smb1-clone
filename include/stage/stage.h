#pragma once
#include "entities/entities.h"

typedef struct
{
    Entity* mario;
    Entity* blocks;
} Stage;

Stage* Stage_Create();

void Stage_Tick(Stage* stage);

void Stage_Render(Stage* stage, Camera* camera);

void Stage_Free(Stage* stage);