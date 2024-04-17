/*
** EPITECH PROJECT, 2023
** $INIT.C
** File description:
** initializes everything
*/

#include "../include/radar.h"

void allocate_mem(global_t *global)
{
    global->window = malloc(sizeof(window_t));
    global->background = malloc(sizeof(object_t));
    global->planes = malloc(sizeof(object_t) * (global->num_planes));
    global->towers = malloc(sizeof(object_t) * (global->num_towers));
    global->clock = malloc(sizeof(times_t));
    global->clock_timer = malloc(sizeof(times_t));
}

void destroy(global_t *global)
{
    sfRenderWindow_destroy(global->window->window);
    free(global->window);
    sfSprite_destroy(global->background->sprite);
    free(global->background);
    for (int i = 0; i < global->num_towers; i++)
        sfSprite_destroy(global->towers[i].sprite);
    free(global->towers);
    sfClock_destroy(global->clock->clock);
    free(global->clock);
    sfClock_destroy(global->clock_timer->clock);
    free(global->clock_timer);
    free(global->planes);
}

int are_all_planes_destroyed(global_t *global)
{
    for (int i = 0; i < global->num_planes; i++) {
        if (global->planes[i].sprite != NULL) {
            return 0;
        }
    }
    return 1;
}

void destroy_plane(global_t *global, int i)
{
    sfSprite_destroy(global->planes[i].sprite);
    global->planes[i].sprite = NULL;
}

void init(global_t *global)
{
    allocate_mem(global);
    set_window(global->window);
    set_background(global);
    set_clock(global);
    set_towers(global);
}
