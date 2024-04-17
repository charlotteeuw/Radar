/*
** EPITECH PROJECT, 2023
** $WINDOW.C
** File description:
** opens window
*/

#include "../include/radar.h"

char *open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat file_type;
    char *buffer;
    int size = 0;
    int size_read = 0;

    stat(filepath, &file_type);
    size = file_type.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    size_read = read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

int read_file(char *filepath, global_t *global)
{
    char *buffer = open_file(filepath);
    int planes = 0;
    int towers = 0;

    get_nb_entities(buffer, &planes, &towers);
    global->num_towers = towers;
    global->num_planes = planes;
    global->plane = malloc(sizeof(plane_t) * planes);
    global->tower = malloc(sizeof(tower_t) * towers);
    parse_buffer_planes(buffer, global);
    parse_buffer_towers(buffer, global);
}
