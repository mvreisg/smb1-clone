#include "entity/entity.h"
#include <stdlib.h>

Entity** Entity_Allocate(Uint32 amount)
{
    return calloc(amount, sizeof(Entity*));
}

void Entity_Deallocate(Entity** entities)
{
    for (size_t i = 0; i < sizeof(&entities) / sizeof(entities[0]); i++)
        Entity_Free(entities[i]);

    free(entities);
    entities = NULL;
}

Entity* Entity_Create(char* name, SDL_FRect rect)
{
    Entity* entity = malloc(sizeof(Entity));

    entity->name = name;
    entity->rect = rect;

    return entity;
}

void Entity_Free(Entity* entity)
{
    free(entity);
    entity = NULL;
}