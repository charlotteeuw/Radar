/*
** EPITECH PROJECT, 2023
** $CHECK_EVENT.C
** File description:
** checks events happening
*/

#include "../include/radar.h"

void check_event(global_t *global, sfEvent event, int i, int j)
{
    while (sfRenderWindow_pollEvent(global->window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(global->window->window);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyL) {
            global->visibility_hitbox = (global->visibility_hitbox + 1) % 2;
        }
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyS) {
            global->visibility_planes = (global->visibility_planes + 1) % 2;
        }
    }
}

void draw_towers(global_t *global)
{
    for (int j = 0; j < global->num_towers; j++) {
        if (global->visibility_planes == 1) {
            sfRenderWindow_drawSprite(global->window->window,
            global->towers[j].sprite, NULL);
        }
        if (global->visibility_hitbox == 1)
            sfRenderWindow_drawCircleShape(global->window->window,
            global->towers[j].circle, NULL);
    }
}

void draw_planes(global_t *global)
{
    for (int i = 0; i < global->num_planes; i++) {
        if (global->clock_timer->seconds < global->plane[i].delay)
            return;
        if (global->planes[i].sprite != NULL) {
            show_sprite(global, i);
            show_hitbox(i, global);
        }
    }
}

void show_hitbox(int i, global_t *global)
{
    if (global->visibility_hitbox == 1) {
        sfRenderWindow_drawRectangleShape(global->window->window,
        global->planes[i].rectangle, NULL);
    }
}

void show_sprite(global_t *global, int i)
{
    if (global->visibility_planes == 1) {
        sfRenderWindow_drawSprite(global->window->window,
            global->planes[i].sprite, NULL);
    }
}
