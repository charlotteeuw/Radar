/*
** EPITECH PROJECT, 2023
** $PARSE.C
** File description:
** parse buffer
*/

#include "../include/radar.h"

void parse_buffer_planes(char *buffer, global_t *global)
{
    int j = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'A') {
            i++;
            global->plane[j].departure_x = check_info(buffer, &i);
            global->plane[j].departure_y = check_info(buffer, &i);
            global->plane[j].arrival_x = check_info(buffer, &i);
            global->plane[j].arrival_y = check_info(buffer, &i);
            global->plane[j].speed = check_info(buffer, &i);
            global->plane[j].delay = check_info(buffer, &i);
            j++;
        }
        if (buffer[i] != '\0')
            i++;
    }
}

void parse_buffer_towers(char *buffer, global_t *global)
{
    int j = 0;
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'T') {
            i++;
            global->tower[j].coordinate_x = check_info(buffer, &i);
            global->tower[j].coordinate_y = check_info(buffer, &i);
            global->tower[j].radius = check_info(buffer, &i);
            j++;
        }
        i++;
    }
}
