#include "texture.h"
#include "image.h"
#include "renderer.h"

Boot_Texture* Boot_Texture_CreateTexture(Boot_Renderer* renderer_context, Boot_Image* image)
{
    Boot_Texture* texture = (Boot_Texture*)malloc(sizeof(Boot_Texture));

    texture->texture = SDL_CreateTextureFromSurface(renderer_context->renderer, image->surface);

    return texture;
}