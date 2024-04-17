/*
** EPITECH PROJECT, 2023
** $CALCULATE
** File description:
** Calculate functions
*/

#include "../include/radar.h"

int length_number(int number)
{
    int length = 0;

    if (number == 0)
        length = 1;
    else
        while (number != 0) {
            length++;
            number = number / 10;
        }
    return length;
}

void reverse(int start, int end, char *str)
{
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void convert(int counter, char *str, int *i)
{
    while (counter != 0) {
        str[*i] = (counter % 10) + '0';
        counter /= 10;
        (*i)++;
    }
}

char *int_tostr(int counter)
{
    int len = length_number(counter);
    char *str = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int start = 0;
    int end = 0;

    if (counter == 0) {
        str[i] = '0';
        str[1] = '\0';
        return str;
    }
    str[len] = '\0';
    convert(counter, str, &i);
    end = i - 1;
    reverse(start, end, str);
    return str;
}
