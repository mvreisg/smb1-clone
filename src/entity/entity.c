#include "entity/entity.h"
#include <stdlib.h>

Entity* Entity_Create(Uint32 amount)
{
    return calloc(amount, sizeof(Entity));
}

void Entity_Free(Entity* entity)
{
    free(entity);
    entity = NULL;
}