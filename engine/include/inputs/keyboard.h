#include <SDL2/SDL.h>
#include <stdbool.h>

typedef enum
{
    KEYBOARD_W = 0,
    KEYBOARD_S = 1,
    KEYBOARD_A = 2,
    KEYBOARD_D = 3,
} Boot_Keyboard_Keys;

typedef struct
{
    Boot_Keyboard_Keys* keys;
} Boot_Keyboard;

Boot_Keyboard* Boot_Keyboard_Update();