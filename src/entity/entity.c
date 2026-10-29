#include "entity/entity.h"
#include <stdlib.h>

Entity* Entity_Create(Uint32 amount)
{
    return (Entity*)calloc(amount, sizeof(Entity));
}

void Entity_Free(Entity* entity)
{
    free(entity);
    entity = NULL;
}