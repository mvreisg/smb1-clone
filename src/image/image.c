#include "image/image.h"
#include <stdlib.h>

int Image_Init()
{
    int init_status = SDL_Init(SDL_INIT_VIDEO);
    return init_status;
}

Textures* Image_Create(SDL_Renderer* renderer)
{
    SDL_Texture* mario_texture = IMG_LoadTexture(renderer, "assets/sprites/mario.png");
    SDL_Texture* blocks_texture = IMG_LoadTexture(renderer, "assets/sprites/blocks.png");

    Textures* textures = (Textures*)malloc(sizeof(Textures));

    textures->mario_texture = mario_texture;
    textures->blocks_texture = blocks_texture;

    return textures;
}

void Image_Free(Textures* textures)
{
    SDL_DestroyTexture(textures->mario_texture);
    SDL_DestroyTexture(textures->blocks_texture);

    free(textures);
    textures = NULL;
}