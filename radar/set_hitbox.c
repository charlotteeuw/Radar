/*
** EPITECH PROJECT, 2023
** $SET_HITBOX.C
** File description:
** sets hitbox of the plane
*/

#include "../include/radar.h"

void hitbox(global_t *all, int i)
{
    sfRectangleShape_setSize(all->planes[i].rectangle, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(all->planes[i].rectangle, sfTransparent);
    sfRectangleShape_setOutlineColor(all->planes[i].rectangle, sfGreen);
    sfRectangleShape_setOutlineThickness(all->planes[i].rectangle, 1.0);
    sfRectangleShape_setPosition(all->planes[i].rectangle,
    all->planes[i].position);
    sfRectangleShape_setOrigin(all->planes[i].rectangle, (sfVector2f){10, 10});
}
