#pragma once

#include <SDL2/SDL.h>

typedef enum
{
    SKW_INITIALIZE_VIDEO = 1,
} SKW_Core_InitializationFlags;

typedef enum
{
    SKW_OK = 1,
    SKW_ERROR = 2
} SKW_Core_InitializationStatus;

typedef enum
{
    SKW_QUIT = 1,
    SKW_KEY_DOWN = 2,
} SKW_Core_Events;

typedef enum
{
    SKW_ESCAPE
} SKW_Core_KeyEvent_KeyCode;

SKW_Core_InitializationStatus SKW_Core_Initialize(SKW_Core_InitializationFlags flags);

int SKW_Core_PollEvent(SKW_Core_Events* event, SKW_Core_KeyEvent_KeyCode* key_code);

void SKW_Core_Delay(Uint32 milliseconds);

void SKW_Core_Quit();