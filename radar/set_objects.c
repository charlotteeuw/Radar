/*
** EPITECH PROJECT, 2023
** $SET_OBJECTS.C
** File description:
** sets objects
*/

#include "../include/radar.h"

void set_window(window_t *window)
{
    window->mode = (sfVideoMode){1920, 1080, 32};
    window->window = sfRenderWindow_create(window->mode,
    "My Radar", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 30);
}

void set_object(object_t *object, char *texturePath,
    sfVector2f position, sfVector2f scale)
{
    object->texture = sfTexture_createFromFile(texturePath, NULL);
    object->sprite = sfSprite_create();
    object->scale = scale;
    object->position = position;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setOrigin(object->sprite, object->origin);
    sfSprite_setScale(object->sprite, object->scale);
    sfSprite_setPosition(object->sprite, position);
    return;
}

void set_background(global_t *all)
{
    all->background->origin = (sfVector2f){0, 0};
    set_object(all->background, "./content/map2.png",
    (sfVector2f){0, 0}, (sfVector2f){1, 1});
    return;
}

void set_plane(global_t *all, int i)
{
    float adjacent;
    float opposite;
    float angle = 0;

    all->planes[i].rectangle = sfRectangleShape_create();
    set_object(&all->planes[i], "./content/plane.png",
    (sfVector2f){all->plane[i].departure_x, all->plane[i].departure_y},
    (sfVector2f){0.1, 0.1});
    all->planes[i].origin = (sfVector2f){142, 134};
    sfSprite_setOrigin(all->planes[i].sprite, all->planes[i].origin);
    angle = atan2(all->plane[i].arrival_y - all->plane[i].departure_y,
        all->plane[i].arrival_x - all->plane[i].departure_x);
    adjacent = cos(angle) * all->plane[i].speed;
    opposite = sin(angle) * all->plane[i].speed;
    angle = angle * 180 / PI;
    all->planes[i].offset = (sfVector2f){adjacent, opposite};
    sfSprite_rotate(all->planes[i].sprite, angle);
    sfRectangleShape_rotate(all->planes[i].rectangle, angle);
    hitbox(all, i);
    return;
}

void set_tower(global_t *all, int i)
{
    all->towers[i].circle = sfCircleShape_create();
    all->towers[i].origin = (sfVector2f){384, 573.5};
    set_object(&all->towers[i], "./content/pngegg.png",
    (sfVector2f){all->tower[i].coordinate_x, all->tower[i].coordinate_y},
    (sfVector2f){0.025, 0.025});
    sfCircleShape_setOrigin(all->towers[i].circle,
    (sfVector2f){all->tower[i].radius, all->tower[i].radius});
    sfCircleShape_setFillColor(all->towers[i].circle, sfTransparent);
    sfCircleShape_setOutlineThickness(all->towers[i].circle, 1.0);
    sfCircleShape_setOutlineColor(all->towers[i].circle, sfWhite);
    sfCircleShape_setPosition(all->towers[i].circle, all->towers[i].position);
    sfCircleShape_setRadius(all->towers[i].circle, all->tower[i].radius);
    return;
}
