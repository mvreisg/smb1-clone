#include "graphics/texture.h"
#include "graphics/image.h"
#include "graphics/renderer.h"

Engine_Texture* Engine_Texture_CreateTexture(Engine_Renderer* renderer_context, Engine_Image* image)
{
    Engine_Texture* texture = (Engine_Texture*)malloc(sizeof(Engine_Texture));

    texture->texture = SDL_CreateTextureFromSurface(renderer_context->renderer, image->surface);

    return texture;
}

void Engine_Texture_FreeTexture(Engine_Texture* texture)
{
    SDL_DestroyTexture(texture->texture);
    free(texture);
    texture = NULL;
}