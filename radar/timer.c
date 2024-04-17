/*
** EPITECH PROJECT, 2023
** $TIMER.C
** File description:
** function for timer
*/

#include "../include/radar.h"

void timer(global_t *global)
{
    sfText *timer = sfText_create();
    char *str = int_tostr(global->clock_timer->seconds);
    sfFont *font = sfFont_createFromFile("./content/retro.ttf");

    sfText_setFont(timer, font);
    sfText_setCharacterSize(timer, 50);
    sfText_setString(timer, str);
    free(str);
    sfText_setPosition(timer, (sfVector2f){1850, 0});
    sfRenderWindow_drawText(global->window->window, timer, NULL);
}
