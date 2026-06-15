#include "keyboard.h"

Boot_Keyboard* Boot_Keyboard_Update()
{
    const Uint8* sdl_keyboard = SDL_GetKeyboardState(NULL);

    Boot_Keyboard* keyboard = (Boot_Keyboard*)malloc(sizeof(Boot_Keyboard));

    keyboard->keys = (Boot_Keyboard_Keys*)malloc(sizeof(Boot_Keyboard_Keys) * 4);

    keyboard->keys[KEYBOARD_W] = sdl_keyboard[SDL_SCANCODE_W];

    bool wPressed = keyboard[SDL_SCANCODE_W];
    bool aPressed = keyboard[SDL_SCANCODE_A];
    bool sPressed = keyboard[SDL_SCANCODE_S];
    bool dPressed = keyboard[SDL_SCANCODE_D];
}