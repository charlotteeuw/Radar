/*
** EPITECH PROJECT, 2023
** $MAIN.C
** File description:
** main
*/

#include "../include/radar.h"

int main(int argc, char **argv)
{
    char *filepath;
    global_t *global = malloc(sizeof(global_t));

    if (argc != 2) {
        my_putstr("./my_radar: bad arguments: 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        return 84;
    }
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        information();
        return 0;
    }
    filepath = argv[1];
    if (read_file(filepath, global) == 84)
        return 84;
    init(global);
    window(global);
    destroy(global);
    return 0;
}
