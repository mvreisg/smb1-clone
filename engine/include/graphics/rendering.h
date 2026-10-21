#pragma once

#include "graphics/window.h"
#include "math/geometry.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef enum
{
    ENGINE_IMAGE_INITIALIZE_PNG
} Engine_ImageInitializationFlags;

typedef struct
{
    SDL_Surface* surface;
} Engine_Image;

typedef enum
{
    ENGINE_RENDERER_INITIALIZE_ACCELERATED
} Engine_RendererInitializationFlags;

typedef struct
{
    SDL_Renderer* renderer;
} Engine_Renderer;

typedef struct
{
    SDL_Texture* texture;
} Engine_Texture;

typedef struct
{
    char name[50];
    Engine_IntRectangle rectangle;
} Engine_Sprite;

typedef struct
{
    Engine_Image* image;
    Engine_Texture* texture;
} Engine_Rendering_Data;

Engine_ImageInitializationFlags Engine_InitializeImages(Engine_ImageInitializationFlags flags);

Engine_Image* Engine_LoadImage(char* path);

void Engine_FreeImage(Engine_Image* image);

Engine_Renderer* Engine_CreateRenderer(Engine_Window* window_context, Engine_RendererInitializationFlags flags);

void Engine_FreeRenderer(Engine_Renderer* renderer);

int Engine_ClearRenderer(Engine_Renderer* renderer);

int Engine_CopyTextureToRenderer(Engine_Renderer* renderer, Engine_Texture* texture, Engine_IntRectangle* crop_rectangle, Engine_IntRectangle* actual_rectangle);

void Engine_PresentRenderer(Engine_Renderer* renderer);

Engine_Texture* Engine_CreateTexture(Engine_Renderer* renderer_context, Engine_Image* image);

void Engine_FreeTexture(Engine_Texture* texture);

Engine_Rendering_Data* Engine_CreateRenderingData(Engine_Renderer* renderer, char* image_path);

void Engine_FreeRenderingData(Engine_Rendering_Data* renderer);

Engine_Sprite* Engine_CreateSprite(char* name, Engine_IntRectangle rectangle);

void Engine_FreeSprite(Engine_Sprite* sprite);