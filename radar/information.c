/*
** EPITECH PROJECT, 2023
** $INFORMATION
** File description:
** -h
*/

#include "../include/radar.h"

void information(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putchar('\n');
    my_putstr("USAGE\n");
    my_putstr("     ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("     path_to_script     The path to the script file.\n");
    my_putstr("OPTIONS\n");
    my_putstr("     -h          print the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("     'L' key      enable/disable hitboxes and areas.\n");
    my_putstr("     'S' key      enable/disable sprites.\n");
}
