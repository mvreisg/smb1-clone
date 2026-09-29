#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef enum
{
    ENGINE_KEYBOARD_W = 0,
    ENGINE_KEYBOARD_S = 1,
    ENGINE_KEYBOARD_A = 2,
    ENGINE_KEYBOARD_D = 3,
} Engine_Keyboard_Keys;

typedef struct
{
    bool is_pressed;
} Engine_Keyboard_Key;

typedef struct
{
    Engine_Keyboard_Key* keys;
} Engine_Keyboard;

Engine_Keyboard* Engine_Keyboard_Create();

void Engine_Keyboard_Update(Engine_Keyboard* keyboard);