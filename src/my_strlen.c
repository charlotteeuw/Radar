/*
** EPITECH PROJECT, 2023
** $MY_STRLEN
** File description:
** Counts the number of characters in a string
*/

#include "../include/radar.h"

int my_strlen(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0'){
        count++;
        i++;
    }
    return count;
}
