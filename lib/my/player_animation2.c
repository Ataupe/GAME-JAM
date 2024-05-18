/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** player_animation.c
*/

#include "my.h"

void player_animation_up2(float t, window_t *main, list_t *list)
{
    int i = sfRenderWindow_getSize(main->window).y;

    list->txtrs[1].rectangle.top = 192;
    if (t > 0.05) {
        list->txtrs[1].rectangle.left += 64;
        sfClock_restart(list->txtrs[1].clock);
    }
    if (list->txtrs[1].rectangle.left == 256) {
        list->txtrs[1].rectangle.left = 0;
    }
}

void player_animation_down2(float t, window_t *main, list_t *list)
{
    int i = sfRenderWindow_getSize(main->window).y;

    list->txtrs[1].rectangle.top = 0;
    if (t > 0.05) {
        list->txtrs[1].rectangle.left += 64;
        sfClock_restart(list->txtrs[1].clock);
    }
    if (list->txtrs[1].rectangle.left == 256) {
        list->txtrs[1].rectangle.left = 0;
    }
}

void player_animation_left2(float t, window_t *main, list_t *list)
{
    int i = sfRenderWindow_getSize(main->window).y;

    list->txtrs[1].rectangle.top = 64;
    if (t > 0.05) {
        list->txtrs[1].rectangle.left += 64;
        sfClock_restart(list->txtrs[1].clock);
    }
    if (list->txtrs[1].rectangle.left == 256) {
        list->txtrs[1].rectangle.left = 0;
    }
}

void player_animation_right2(float t, window_t *main, list_t *list)
{
    int i = sfRenderWindow_getSize(main->window).y;

    list->txtrs[1].rectangle.top = 128;
    if (t > 0.05) {
        list->txtrs[1].rectangle.left += 64;
        sfClock_restart(list->txtrs[1].clock);
    }
    if (list->txtrs[1].rectangle.left == 256) {
        list->txtrs[1].rectangle.left = 0;
    }
}
