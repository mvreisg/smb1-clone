#include "graphics/texture.h"
#include "graphics/image.h"
#include "graphics/renderer.h"

SKW_Texture* SKW_Texture_CreateTexture(SKW_Renderer* renderer_context, SKW_Image* image)
{
    SKW_Texture* texture = (SKW_Texture*)malloc(sizeof(SKW_Texture));

    texture->texture = SDL_CreateTextureFromSurface(renderer_context->renderer, image->surface);

    return texture;
}

void SKW_Texture_FreeTexture(SKW_Texture* texture)
{
    SDL_DestroyTexture(texture->texture);
    free(texture);
    texture = NULL;
}