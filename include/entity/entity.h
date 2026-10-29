#pragma once
#include <SDL.h>

typedef struct
{
    SDL_FRect rect;
} Entity;

Entity* Entity_Create(Uint32 amount);

void Entity_Free(Entity* entity);