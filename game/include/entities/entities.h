#pragma once

#include "engine/include/graphics/rendering.h"
#include "engine/include/math/geometry.h"

typedef struct
{
    Engine_FloatRectangle scene_rectangle;
    Engine_Spritesheet* spritesheet;
} Entity;

Entity* Game_Entity_Instantiate(Engine_FloatRectangle rectangle, Engine_FloatRectangle scale);

void Game_Entity_Free(Entity* entity);