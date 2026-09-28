#pragma once

typedef struct
{
    float x;
    float y;
} SKW_FloatPoint;

typedef struct
{
    float width;
    float height;
} SKW_FloatDimension;

typedef struct
{
    SKW_FloatPoint point;
    SKW_FloatDimension dimension;
} SKW_FloatRectangle;

typedef struct
{
    int x;
    int y;
} SKW_IntPoint;

typedef struct
{
    int width;
    int height;
} SKW_IntDimension;

typedef struct
{
    SKW_IntPoint point;
    SKW_IntDimension dimension;
} SKW_IntRectangle;