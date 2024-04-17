/*
** EPITECH PROJECT, 2023
** $FIND_MINMAX.C
** File description:
** finds min and max
*/

#include "../include/radar.h"

float find_min(float scalar1, float scalar2, float scalar3, float scalar4)
{
    float min = 0;

    if (scalar1 < scalar2 && scalar1 < scalar3 && scalar1 < scalar4)
        min = scalar1;
    if (scalar2 < scalar1 && scalar2 < scalar3 && scalar2 < scalar4)
        min = scalar2;
    if (scalar3 < scalar2 && scalar3 < scalar1 && scalar3 < scalar4)
        min = scalar3;
    if (scalar4 < scalar2 && scalar4 < scalar3 && scalar4 < scalar1)
        min = scalar4;
    return min;
}

float find_max(float scalar1, float scalar2, float scalar3, float scalar4)
{
    float max = 0;

    if (scalar1 > scalar2 && scalar1 > scalar3 && scalar1 > scalar4)
        max = scalar1;
    if (scalar2 > scalar1 && scalar2 > scalar3 && scalar2 > scalar4)
        max = scalar2;
    if (scalar3 > scalar2 && scalar3 > scalar1 && scalar3 > scalar4)
        max = scalar3;
    if (scalar4 > scalar2 && scalar4 > scalar3 && scalar4 > scalar1)
        max = scalar4;
    return max;
}
