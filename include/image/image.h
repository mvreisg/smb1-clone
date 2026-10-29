#include <SDL.h>
#include <SDL_image.h>

typedef struct
{
    SDL_Texture* mario_texture;
    SDL_Texture* blocks_texture;
} Textures;

int Image_Init();

Textures* Image_Create(SDL_Renderer* renderer);

void Image_Free(Textures* textures);