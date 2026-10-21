#pragma once

#include <SDL2/SDL.h>

typedef enum
{
    ENGINE_INITIALIZE_VIDEO,
} Engine_Core_InitializationFlags;

typedef enum
{
    ENGINE_OK,
    ENGINE_ERROR
} Engine_Core_InitializationStatus;

typedef enum
{
    ENGINE_QUIT,
    ENGINE_KEY_DOWN,
} Engine_Core_Events;

typedef enum
{
    ENGINE_KEYCODE_ESCAPE,
    ENGINE_KEYCODE_UP,
    ENGINE_KEYCODE_DOWN,
    ENGINE_KEYCODE_LEFT,
    ENGINE_KEYCODE_RIGHT,
} Engine_Core_KeyEvent_KeyCode;

Engine_Core_InitializationStatus Engine_Core_Initialize(Engine_Core_InitializationFlags flags);

int Engine_Core_PollEvent(Engine_Core_Events* event, Engine_Core_KeyEvent_KeyCode* key_code);

void Engine_Core_Delay(Uint32 milliseconds);

void Engine_Core_Quit();