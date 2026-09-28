#include "inputs/keyboard.h"

SKW_Keyboard* SKW_Keyboard_Create()
{
    SKW_Keyboard* keyboard = (SKW_Keyboard*)malloc(sizeof(SKW_Keyboard));

    keyboard->keys = (SKW_Keyboard_Key*)malloc(sizeof(SKW_Keyboard_Key) * 4);

    return keyboard;
}

void SKW_Keyboard_Update(SKW_Keyboard* keyboard)
{
    const Uint8* sdl_keyboard = SDL_GetKeyboardState(NULL);

    keyboard->keys = (SKW_Keyboard_Key*)malloc(sizeof(SKW_Keyboard_Key) * 4);

    keyboard->keys[SKW_KEYBOARD_W].is_pressed = sdl_keyboard[SDL_SCANCODE_W];
}