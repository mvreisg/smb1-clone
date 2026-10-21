#include "inputs/keyboard.h"
#include <SDL2/SDL.h>

Engine_Keyboard* Engine_Keyboard_Create()
{
    Engine_Keyboard* keyboard = (Engine_Keyboard*)malloc(sizeof(Engine_Keyboard));
    return keyboard;
}

void Engine_Keyboard_Update(Engine_Keyboard* keyboard)
{
    const Uint8* sdl_keyboard = SDL_GetKeyboardState(NULL);

    keyboard->keys[ENGINE_KEYBOARD_W].is_pressed = sdl_keyboard[SDL_SCANCODE_W];
    keyboard->keys[ENGINE_KEYBOARD_S].is_pressed = sdl_keyboard[SDL_SCANCODE_S];
    keyboard->keys[ENGINE_KEYBOARD_A].is_pressed = sdl_keyboard[SDL_SCANCODE_A];
    keyboard->keys[ENGINE_KEYBOARD_D].is_pressed = sdl_keyboard[SDL_SCANCODE_D];
}

void Engine_Keyboard_Free(Engine_Keyboard* keyboard)
{
    free(keyboard);
    keyboard = NULL;
}