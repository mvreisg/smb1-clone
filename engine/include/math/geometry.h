#pragma once

typedef struct
{
    float x;
    float y;
} Engine_FloatPoint;

typedef struct
{
    float width;
    float height;
} Engine_FloatDimension;

typedef struct
{
    Engine_FloatPoint point;
    Engine_FloatDimension dimension;
} Engine_FloatRectangle;

typedef struct
{
    int x;
    int y;
} Engine_IntPoint;

typedef struct
{
    int width;
    int height;
} Engine_IntDimension;

typedef struct
{
    Engine_IntPoint point;
    Engine_IntDimension dimension;
} Engine_IntRectangle;