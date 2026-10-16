#pragma once

#include "engine/include/graphics/renderer.h"

typedef struct
{
    Engine_Image* image;
    Engine_Texture* texture;
} Game_Rendering_Data;

Game_Rendering_Data* Game_Renderer_CreateRenderingData(Engine_Renderer* renderer, char* image_path);