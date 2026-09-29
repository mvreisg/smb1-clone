#include "inputs/keyboard.h"

Engine_Keyboard* Engine_Keyboard_Create()
{
    Engine_Keyboard* keyboard = (Engine_Keyboard*)malloc(sizeof(Engine_Keyboard));

    keyboard->keys = (Engine_Keyboard_Key*)malloc(sizeof(Engine_Keyboard_Key) * 4);

    return keyboard;
}

void Engine_Keyboard_Update(Engine_Keyboard* keyboard)
{
    const Uint8* sdl_keyboard = SDL_GetKeyboardState(NULL);

    keyboard->keys = (Engine_Keyboard_Key*)malloc(sizeof(Engine_Keyboard_Key) * 4);

    keyboard->keys[ENGINE_KEYBOARD_W].is_pressed = sdl_keyboard[SDL_SCANCODE_W];
}