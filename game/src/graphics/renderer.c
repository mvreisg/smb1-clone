#include "game/include/graphics/renderer.h"
#include <stdlib.h>

Game_Rendering_Data* Game_Renderer_CreateRenderingData(Engine_Renderer* renderer, char* image_path)
{
    Game_Rendering_Data* rendering_data = (Game_Rendering_Data*)malloc(sizeof(Game_Rendering_Data));
    rendering_data->image = Engine_Image_LoadImage(image_path);
    rendering_data->texture = Engine_Renderer_CreateTexture(renderer, rendering_data->image);
    return rendering_data;
}