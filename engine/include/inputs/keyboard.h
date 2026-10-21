#pragma once

#include <stdbool.h>

typedef enum
{
    ENGINE_KEYBOARD_W,
    ENGINE_KEYBOARD_S,
    ENGINE_KEYBOARD_A,
    ENGINE_KEYBOARD_D,
} Engine_Keyboard_Keys;

typedef struct
{
    bool is_pressed;
} Engine_Keyboard_Key;

typedef struct
{
    Engine_Keyboard_Key keys[4];
} Engine_Keyboard;

Engine_Keyboard* Engine_Keyboard_Create();

void Engine_Keyboard_Update(Engine_Keyboard* keyboard);

void Engine_Keyboard_Free(Engine_Keyboard* keyboard);