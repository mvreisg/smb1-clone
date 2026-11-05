#pragma once
#include <SDL.h>

typedef struct
{
    char* name;
    SDL_FRect rect;
} Entity;

Entity** Entity_Allocate(Uint32 amount);

void Entity_Deallocate(Entity** entities);

Entity* Entity_Create(char* name, SDL_FRect rect);

void Entity_Free(Entity* entity);