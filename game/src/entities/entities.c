#include "game/include/entities/entities.h"

Entity* Game_Entity_Instantiate(Engine_FloatRectangle rectangle, Engine_FloatRectangle scale)
{
    Entity* entity = malloc(sizeof(Entity));

    entity->scene_rectangle = (Engine_FloatRectangle){
        .point = {
            .x = rectangle.point.x,
            .y = rectangle.point.y},
        .dimension = {.width = rectangle.dimension.width * scale.dimension.width, .height = rectangle.dimension.height * scale.dimension.height}};
}

void Game_Entity_Free(Entity* entity)
{
    free(entity);
    entity = NULL;
}