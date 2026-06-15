#include <SDL2/SDL.h>

typedef enum
{
    INITIALIZE_VIDEO = 1,
} InitializationFlags;

typedef enum
{
    STATUS_OK = 1,
    STATUS_ERROR = 2
} InitializationStatus;

InitializationStatus Boot_Main_Initialize(InitializationFlags flags)