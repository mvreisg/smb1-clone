typedef struct
{
    float x;
    float y;
} Boot_FloatPoint;

typedef struct
{
    float width;
    float height;
} Boot_FloatDimension;

typedef struct
{
    Boot_FloatPoint point;
    Boot_FloatDimension dimension;
} Boot_FloatRectangle;

typedef struct
{
    int x;
    int y;
} Boot_IntPoint;

typedef struct
{
    int width;
    int height;
} Boot_IntDimension;

typedef struct
{
    Boot_IntPoint point;
    Boot_IntDimension dimension;
} Boot_IntRectangle;