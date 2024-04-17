/*
** EPITECH PROJECT, 2023
** $COLLISION.C
** File description:
** file for collisions
*/

#include "../include/radar.h"

int are_planes_colliding(sfRectangleShape *rect1, sfRectangleShape *rect2)
{
    sfVector2f position1 = sfRectangleShape_getPosition(rect1);
    sfVector2f position2 = sfRectangleShape_getPosition(rect2);
    sfVector2f size1 = sfRectangleShape_getSize(rect1);
    sfVector2f size2 = sfRectangleShape_getSize(rect2);
    sfFloatRect bounds1 = {position1.x, position1.y, size1.x, size1.y};
    sfFloatRect bounds2 = {position2.x, position2.y, size2.x, size2.y};

    if (bounds1.left + bounds1.width < bounds2.left ||
        bounds1.left > bounds2.left + bounds2.width) {
        return 0;
    }
    if (bounds1.top + bounds1.height < bounds2.top ||
        bounds1.top > bounds2.top + bounds2.height) {
        return 0;
    }
    return 1;
}

int is_inside_tower_area(global_t *global, int plane_index1,
    int plane_index2, sfCircleShape* circle)
{
    sfVector2f circleCenter = sfCircleShape_getPosition(circle);
    sfVector2f position1 =
    sfSprite_getPosition(global->planes[plane_index1].sprite);
    sfVector2f position2 =
    sfSprite_getPosition(global->planes[plane_index2].sprite);
    sfVector2f difference = (sfVector2f){
    circleCenter.x - position1.x,
    circleCenter.y - position1.y
    };
    sfVector2f difference2 = (sfVector2f){
    circleCenter.x - position2.x,
    circleCenter.y - position2.y
    };
    float distance = sqrt(pow(difference.x, 2) + pow(difference.y, 2));
    float distance2 = sqrt(pow(difference2.x, 2) + pow(difference2.y, 2));

    if (distance > sfCircleShape_getRadius(circle) ||
    distance2 > sfCircleShape_getRadius(circle))
        return 1;
    return 0;
}

void destroy_planes(global_t *global, int plane_index1, int plane_index2)
{
    sfSprite_destroy(global->planes[plane_index1].sprite);
    sfRectangleShape_destroy(global->planes[plane_index1].rectangle);
    global->planes[plane_index1].sprite = NULL;
    global->planes[plane_index1].rectangle = NULL;
    sfSprite_destroy(global->planes[plane_index2].sprite);
    sfRectangleShape_destroy(global->planes[plane_index2].rectangle);
    global->planes[plane_index2].sprite = NULL;
    global->planes[plane_index2].rectangle = NULL;
}

void set_outline_color(int plane_index1, int plane_index2,
    global_t *global)
{
    sfRectangleShape_setOutlineColor(
    global->planes[plane_index1].rectangle, sfYellow);
    sfRectangleShape_setOutlineColor(
    global->planes[plane_index2].rectangle, sfYellow);
}

void handle_plane_collisions(global_t *global,
    int plane_index1, int plane_index2)
{
    if (plane_index2 >= global->num_planes ||
    global->planes[plane_index1].rectangle == NULL ||
    global->planes[plane_index2].rectangle == NULL)
        return;
    if (!are_planes_colliding(global->planes[plane_index1].rectangle,
    global->planes[plane_index2].rectangle))
        return;
    for (int k = 0; k < global->num_towers; k++) {
        if (global->planes[plane_index1].sprite == NULL ||
        global->planes[plane_index2].sprite == NULL)
            return;
        if (is_inside_tower_area(global, plane_index1, plane_index2,
        global->towers[k].circle) == 0) {
            set_outline_color(plane_index1, plane_index2, global);
            return;
        }
    }
    destroy_planes(global, plane_index1, plane_index2);
}
