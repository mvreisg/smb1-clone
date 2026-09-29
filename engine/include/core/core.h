#pragma once

#include <SDL2/SDL.h>

typedef enum
{
    ENGINE_INITIALIZE_VIDEO = 1,
} Engine_Core_InitializationFlags;

typedef enum
{
    ENGINE_OK = 1,
    ENGINE_ERROR = 2
} Engine_Core_InitializationStatus;

typedef enum
{
    ENGINE_QUIT = 1,
    ENGINE_KEY_DOWN = 2,
} Engine_Core_Events;

typedef enum
{
    ENGINE_ESCAPE
} Engine_Core_KeyEvent_KeyCode;

Engine_Core_InitializationStatus Engine_Core_Initialize(Engine_Core_InitializationFlags flags);

int Engine_Core_PollEvent(Engine_Core_Events* event, Engine_Core_KeyEvent_KeyCode* key_code);

void Engine_Core_Delay(Uint32 milliseconds);

void Engine_Core_Quit();