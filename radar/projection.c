/*
** EPITECH PROJECT, 2023
** $PROJECTION.C
** File description:
** math projection
*/

#include "../include/radar.h"

float projection_x(sfVector2f corner, sfVector2f axis)
{
    float projection_x = (((corner.x * axis.x) + (corner.y * axis.y)) /
    (pow(axis.x, 2) + pow(axis.y, 2))) * axis.x;

    return projection_x;
}

float projection_y(sfVector2f corner, sfVector2f axis)
{
    float projection_y = (((corner.x * axis.x) + (corner.y * axis.y)) /
    (pow(axis.x, 2) + pow(axis.y, 2))) * axis.y;

    return projection_y;
}

float projections(sfVector2f corner, sfVector2f axis)
{
    float projectionx = projection_x(corner, axis);
    float projectiony = projection_y(corner, axis);
    float scalar = (projectionx * axis.x) + (projectiony * axis.y);

    return scalar;
}
