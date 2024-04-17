/*
** EPITECH PROJECT, 2023
** $WINDOW.C
** File description:
** opens window
*/

#include "../include/radar.h"

void calculate_difference(global_t *global, int i, sfVector2f position)
{
    sfVector2f difference;
    sfVector2f difference_arrival;
    float distance;
    float distance_arrival_departure;

    difference = (sfVector2f){
    global->plane[i].departure_x - position.x,
    global->plane[i].departure_y - position.y
    };
    difference_arrival = (sfVector2f){
    global->plane[i].departure_x - global->plane[i].arrival_x,
    global->plane[i].departure_y - global->plane[i].arrival_y
    };
    distance_arrival_departure = sqrt(pow(difference_arrival.x, 2)
    + pow(difference_arrival.y, 2));
    distance = sqrt(pow(difference.x, 2) + pow(difference.y, 2));
    if (distance > distance_arrival_departure)
        destroy_plane(global, i);
}

void move_plane(global_t *global, int i, sfEvent event, int j)
{
    sfVector2f offset;
    sfVector2f difference;
    sfVector2f difference_arrival;
    sfVector2f position;
    float distance;
    float distance_arrival_departure;

    if (global->clock_timer->seconds < global->plane[i].delay)
        return;
    offset.x = global->planes[i].offset.x * global->clock->seconds;
    offset.y = global->planes[i].offset.y * global->clock->seconds;
    sfSprite_move(global->planes[i].sprite, offset);
    sfRectangleShape_move(global->planes[i].rectangle, offset);
    position = sfSprite_getPosition(global->planes[i].sprite);
    calculate_difference(global, i, position);
}

void increment_i(global_t *global, int *i)
{
    while (*i < global->num_planes && global->planes[*i].sprite == NULL)
        (*i)++;
}

int parse_planes(global_t *global, sfEvent event, int j)
{
    clock(global);
    check_event(global, event, 0, j);
    for (int i = 0; i < global->num_planes - 1; i++) {
        increment_i(global, &i);
        if (i >= global->num_planes)
            break;
        move_plane(global, i, event, j);
        for (j = i + 1; j < global->num_planes; j++) {
            increment_i(global, &j);
            handle_plane_collisions(global, i, j);
        }
        if (are_all_planes_destroyed(global) == 1)
            return 1;
    }
    return 0;
}

void window(global_t *global)
{
    sfEvent event;
    int j = 0;
    int window_game = 0;

    global->visibility_planes = 0;
    global->visibility_hitbox = 0;
    for (int i = 0; i < global->num_planes; i++)
        set_plane(global, i);
    while (sfRenderWindow_isOpen(global->window->window)) {
        sfRenderWindow_clear(global->window->window, sfWhite);
        sfRenderWindow_drawSprite(global->window->window,
        global->background->sprite, NULL);
        timer(global);
        draw_towers(global);
        draw_planes(global);
        if (parse_planes(global, event, j) == 1)
            return;
        sfClock_restart(global->clock->clock);
        sfRenderWindow_display(global->window->window);
    }
}
