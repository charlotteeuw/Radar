/*
** EPITECH PROJECT, 2023
** $FILE_INFO.C
** File description:
** info about the file
*/

#include "../include/radar.h"

void get_nb_entities(char *buffer, int *planes, int *towers)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'A')
            (*planes)++;
        if (buffer[i] == 'T')
            (*towers)++;
    }
}

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int check_info(char *str, int *i)
{
    int number = 0;

    while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
        (*i)++;
    while (str[*i] != ' ' && str[*i] != '\t' &&
    str[*i] != '\0' && str[*i] != '\n') {
        if (my_char_isnum(str[*i]) == 1) {
            number = number * 10 + str[*i] - '0';
            (*i)++;
        } else {
            return -1;
        }
    }
    return number;
}
