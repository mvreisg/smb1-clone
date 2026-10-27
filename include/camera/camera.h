#pragma once
#include <SDL.h>

typedef struct
{
    SDL_FRect rect;
} Camera;

Camera* Camera_Create(SDL_FRect rect);

void Camera_Free(Camera* camera);