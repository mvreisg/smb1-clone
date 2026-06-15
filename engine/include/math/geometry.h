typedef struct
{
    float x;
    float y;
} FloatPoint;

typedef struct
{
    float width;
    float height;
} FloatDimension;

typedef struct
{
    FloatPoint point;
    FloatDimension dimension;
} FloatRectangle;

typedef struct
{
    int x;
    int y;
} IntPoint;

typedef struct
{
    int width;
    int height;
} IntDimension;

typedef struct
{
    IntPoint point;
    IntDimension dimension;
} IntRectangle;