#include <SDL2/SDL.h>

typedef enum
{
    INITIALIZE_VIDEO = 1,
} Boot_Core_InitializationFlags;

typedef enum
{
    STATUS_OK = 1,
    STATUS_ERROR = 2
} Boot_Core_InitializationStatus;

typedef enum
{
    QUIT = 1,
    KEY_DOWN = 2,
} Boot_Core_Events;

Boot_Core_InitializationStatus Boot_Core_Initialize(Boot_Core_InitializationFlags flags);