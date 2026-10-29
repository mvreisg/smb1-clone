#include "camera/camera.h"
#include <SDL.h>
#include <stdlib.h>

Camera* Camera_Create(SDL_FRect rect)
{
    Camera* camera = (Camera*)malloc(sizeof(Camera));
    camera->rect = rect;

    return camera;
}

void Camera_Free(Camera* camera)
{
    free(camera);
    camera = NULL;
}