#include <SDL2/SDL.h>
#include "geometry.h"

typedef struct
{
    int scale;
    Rectangle rectangle;
    SDL_Texture* texture;
} Sprite;