/*
** EPITECH PROJECT, 2023
** $COUNT_CHAR
** File description:
** counts characters
*/

#include "../include/radar.h"

int count_nb_lines(char *buffer)
{
    int nb_lines = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nb_lines++;
    }
    return nb_lines;
}

int count_nb_columns(char *buffer)
{
    int nb_columns = 0;

    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        nb_columns++;
    }
    return nb_columns;
}
