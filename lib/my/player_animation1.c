/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** player_animation.c
*/

#include "my.h"

void player_animation_up1(float t, window_t *main, list_t *list)
{
    int i = sfRenderWindow_getSize(main->window).y;

    list->txtrs[0].rectangle.top = 150;
    if (t > 0.05) {
        list->txtrs[0].rectangle.left += 50;
        sfClock_restart(list->txtrs[0].clock);
    }
    if (list->txtrs[0].rectangle.left == 250) {
        list->txtrs[0].rectangle.left = 0;
    }
}

void player_animation_down1(float t, window_t *main, list_t *list)
{
    int i = sfRenderWindow_getSize(main->window).y;

    list->txtrs[0].rectangle.top = 0;
    if (t > 0.05) {
        list->txtrs[0].rectangle.left += 50;
        sfClock_restart(list->txtrs[0].clock);
    }
    if (list->txtrs[0].rectangle.left == 250) {
        list->txtrs[0].rectangle.left = 0;
    }
}

void player_animation_left1(float t, window_t *main, list_t *list)
{
    int i = sfRenderWindow_getSize(main->window).y;

    list->txtrs[0].rectangle.top = 50;
    if (t > 0.05) {
        list->txtrs[0].rectangle.left += 50;
        sfClock_restart(list->txtrs[0].clock);
    }
    if (list->txtrs[0].rectangle.left == 250) {
        list->txtrs[0].rectangle.left = 0;
    }
}

void player_animation_right1(float t, window_t *main, list_t *list)
{
    int i = sfRenderWindow_getSize(main->window).y;

    list->txtrs[0].rectangle.top = 100;
    if (t > 0.05) {
        list->txtrs[0].rectangle.left += 50;
        sfClock_restart(list->txtrs[0].clock);
    }
    if (list->txtrs[0].rectangle.left == 250) {
        list->txtrs[0].rectangle.left = 0;
    }
}
