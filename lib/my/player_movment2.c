/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** player_movment.c
*/

#include "my.h"

static int is_pixel_black(list_t *list, int axis, int dir)
{
    sfImage *colisions = sfImage_createFromFile("./extra/game/colision10.jpg");
    float x = (list->txtrs[1].position.x + 32);
    float y = (list->txtrs[1].position.y + 54);
    sfColor pixel_color;

    if (axis == 0)
        pixel_color = sfImage_getPixel(colisions, (x + dir), y);
    if (axis == 1)
        pixel_color = sfImage_getPixel(colisions, x, (y + dir));
    if (pixel_color.r == 0 && pixel_color.g == 0 && pixel_color.b == 0) {
        sfImage_destroy(colisions);
        return 1;
    }
    sfImage_destroy(colisions);
    return 0;
}

static void player_up(float t, window_t *main, list_t *list)
{
    sfSprite_setPosition(list->txtrs[1].sprite, list->txtrs[1].position);
    player_animation_up2(t, main, list);
    if (is_pixel_black(list, 1, -8) == 0)
        list->txtrs[1].position.y -= 7;
}

static void player_down(float t, window_t *main, list_t *list)
{
    sfSprite_setPosition(list->txtrs[1].sprite, list->txtrs[1].position);
    player_animation_down2(t, main, list);
    if (is_pixel_black(list, 1, 8) == 0)
        list->txtrs[1].position.y += 7;
}

static void player_left(float t, window_t *main, list_t *list)
{
    sfSprite_setPosition(list->txtrs[1].sprite, list->txtrs[1].position);
    player_animation_left2(t, main, list);
    if (is_pixel_black(list, 0, -8) == 0)
        list->txtrs[1].position.x -= 7;
}

static void player_right(float t, window_t *main, list_t *list)
{
    sfSprite_setPosition(list->txtrs[1].sprite, list->txtrs[1].position);
    player_animation_right2(t, main, list);
    if (is_pixel_black(list, 0, 8) == 0)
        list->txtrs[1].position.x += 7;
}

void player_conditions_2(float t, window_t *main, list_t *list)
{
    float t2 = 0;

    if (sfKeyboard_isKeyPressed(sfKeyUp))
        player_up(t, main, list);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        player_left(t, main, list);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        player_down(t, main, list);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        player_right(t, main, list);
}
