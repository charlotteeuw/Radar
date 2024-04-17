/*
** EPITECH PROJECT, 2023
** $RADAR.H
** File description:
** radar.h
*/

#ifndef RADAR_H_
    #define RADAR_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <math.h>

    #define PI 3.141592653589793238462643383279502884197

typedef struct plane_s {
    int departure_x;
    int departure_y;
    int arrival_x;
    int arrival_y;
    int speed;
    int delay;
} plane_t;

typedef struct tower_s {
    int coordinate_x;
    int coordinate_y;
    int radius;
} tower_t;

typedef struct object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f origin;
    sfVector2f offset;
    sfVector2i temp;
    sfCircleShape *circle;
    sfRectangleShape *rectangle;
} object_t;

typedef struct window_s {
    sfVideoMode mode;
    sfRenderWindow* window;
} window_t;

typedef struct times_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} times_t;

typedef struct global_s {
    int num_objects;
    int num_planes;
    int num_towers;
    float angle;
    window_t *window;
    tower_t *tower;
    plane_t *plane;
    object_t *background;
    object_t *planes;
    object_t *towers;
    times_t *clock;
    times_t *clock_timer;
    int visibility_planes;
    int visibility_hitbox;
    sfVector2i mouse;
} global_t;

int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
void information(void);
int main(int argc, char **argv);
void allocate_mem(global_t *all);
void destroy(global_t *all);
void init(global_t *all);
void set_window(window_t *window);
void set_object(object_t *object, char *texturePath,
    sfVector2f position, sfVector2f scale);
void set_background(global_t *all);
void set_plane(global_t *all, int i);
char *open_file(char *filepath);
void check_event(global_t *global, sfEvent event, int i, int j);
void window(global_t *global);
int count_nb_lines(char *buffer);
int count_nb_columns(char *buffer);
int read_file(char *filepath, global_t *global);
void set_tower(global_t *all, int i);
void get_nb_entities(char *buffer, int *planes, int *towers);
void parse_buffer_planes(char *buffer, global_t *global);
void parse_buffer_towers(char *buffer, global_t *global);
int check_info(char *str, int *i);
void set_clock(global_t *all);
void timer(global_t *global);
char *int_tostr(int counter);
void convert(int counter, char *str, int *i);
void reverse(int start, int end, char *str);
int length_number(int number);
void hitbox(global_t *all, int i);
void show_hitbox(int i, global_t *global);
int parse_planes(global_t *global, sfEvent event, int j);
void clock(global_t *global);
void draw_planes(global_t *global);
void show_sprite(global_t *global, int i);
int are_planes_colliding(sfRectangleShape* rect1, sfRectangleShape* rect2);
int is_inside_tower_area(global_t *global, int plane_index1, int plane_index2,
    sfCircleShape* circle);
void handle_plane_collisions(global_t *global, int plane_index1,
    int plane_index2);
float find_min(float scalar1, float scalar2, float scalar3, float scalar4);
float find_max(float scalar1, float scalar2, float scalar3, float scalar4);
float projection_x(sfVector2f corner, sfVector2f axis);
float projection_y(sfVector2f corner, sfVector2f axis);
float projections(sfVector2f corner, sfVector2f axis);
void destroy_plane(global_t *global, int i);
int are_all_planes_destroyed(global_t *global);
void draw_towers(global_t *global);
void set_towers(global_t *global);

#endif
