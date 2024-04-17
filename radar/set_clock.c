/*
** EPITECH PROJECT, 2023
** $SET_CLOCK.C
** File description:
** sets clocks
*/

#include "../include/radar.h"

void set_towers(global_t *global)
{
    for (int i = 0; i < global->num_towers; i++)
        set_tower(global, i);
}

void set_clock(global_t *all)
{
    all->clock->clock = sfClock_create();
    all->clock->time = sfClock_getElapsedTime(all->clock->clock);
    all->clock->seconds = all->clock->time.microseconds / 1000000.0;
    all->clock_timer->clock = sfClock_create();
    all->clock_timer->time = sfClock_getElapsedTime(all->clock_timer->clock);
    all->clock_timer->seconds = all->clock_timer->time.microseconds /
    1000000.0;
}

void clock(global_t *global)
{
    global->clock->time = sfClock_getElapsedTime(global->clock->clock);
    global->clock->seconds = global->clock->time.microseconds / 1000000.0;
    global->clock_timer->time =
    sfClock_getElapsedTime(global->clock_timer->clock);
    global->clock_timer->seconds = global->clock_timer->time.microseconds /
    1000000.0;
}
