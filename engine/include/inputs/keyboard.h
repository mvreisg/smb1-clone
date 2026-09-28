#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef enum
{
    SKW_KEYBOARD_W = 0,
    SKW_KEYBOARD_S = 1,
    SKW_KEYBOARD_A = 2,
    SKW_KEYBOARD_D = 3,
} SKW_Keyboard_Keys;

typedef struct
{
    bool is_pressed;
} SKW_Keyboard_Key;

typedef struct
{
    SKW_Keyboard_Key* keys;
} SKW_Keyboard;

SKW_Keyboard* SKW_Keyboard_Create();

void SKW_Keyboard_Update(SKW_Keyboard* keyboard);