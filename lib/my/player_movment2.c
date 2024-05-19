/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** player_movment.c
*/

#include "my.h"

static void switch_colision(window_t *main)
{
    if (main->map_chose == 0)
        main->colision = "extra/game/colision10.png";
    if (main->map_chose == 1)
        main->colision = "extra/game/colision15.png";
    if (main->map_chose == 2)
        main->colision = "extra/game/colision20.jpg";
}

static int is_pixel_black(window_t *main, list_t *list, int axis, int dir)
{
    sfImage *colisions = sfImage_createFromFile(main->colision);
    float x = (list->txtrs[1].position.x + 25);
    float y = (list->txtrs[1].position.y + 45);
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
    if (is_pixel_black(main, list, 1, -8) == 0)
        list->txtrs[1].position.y -= 7;
}

static void player_down(float t, window_t *main, list_t *list)
{
    sfSprite_setPosition(list->txtrs[1].sprite, list->txtrs[1].position);
    player_animation_down2(t, main, list);
    if (is_pixel_black(main, list, 1, 8) == 0)
        list->txtrs[1].position.y += 7;
}

static void player_left(float t, window_t *main, list_t *list)
{
    sfSprite_setPosition(list->txtrs[1].sprite, list->txtrs[1].position);
    player_animation_left2(t, main, list);
    if (is_pixel_black(main, list, 0, -8) == 0)
        list->txtrs[1].position.x -= 7;
}

static void player_right(float t, window_t *main, list_t *list)
{
    sfSprite_setPosition(list->txtrs[1].sprite, list->txtrs[1].position);
    player_animation_right2(t, main, list);
    if (is_pixel_black(main, list, 0, 8) == 0)
        list->txtrs[1].position.x += 7;
}

void player_conditions_2(float t, window_t *main, list_t *list)
{
    float t2 = 0;

    switch_colision(main);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        player_up(t, main, list);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        player_left(t, main, list);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        player_down(t, main, list);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        player_right(t, main, list);
}
