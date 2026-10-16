#pragma once

#include "math/geometry.h"

typedef struct
{
    Engine_IntRectangle texture_crop_rectangle;
    Engine_IntRectangle scene_rectangle;
    Engine_IntRectangle camera_rectangle;
} Entity;