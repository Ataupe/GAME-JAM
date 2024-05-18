/*
** EPITECH PROJECT, 2023
** GAME-JAM
** File description:
** game.c
*/

#include "my.h"

static void switch_option(window_t *main)
{
    if (main->map_chose == 0)
        main->background = "extra/game/map_10.png";
    if (main->map_chose == 1)
        main->background = "extra/game/map_15.png";
    if (main->map_chose == 2)
        main->background = "extra/game/map_20.png";
    if (main->time_chose == 3)
        main->sound_select = "extra/sound/30_sec.ogg";
    if (main->time_chose == 4)
        main->sound_select = "extra/sound/60_sec.ogg";
    if (main->time_chose == 5)
        main->sound_select = "extra/sound/fast_music.ogg";
}

static void draw_sprite(window_t *main, list_t *list)
{
    sfRenderWindow_drawSprite(main->window, list->txtrs[0].sprite, NULL);
    sfRenderWindow_drawSprite(main->window, list->txtrs[1].sprite, NULL);
}

static void destroy_sprite(list_t *list)
{
    sfSprite_destroy(list->txtrs[0].sprite);
    sfTexture_destroy(list->txtrs[0].texture);
    sfSprite_destroy(list->txtrs[1].sprite);
    sfTexture_destroy(list->txtrs[1].texture);
}

static void make_players(list_t *list)
{
    list->txtrs[0].texture = sfTexture_createFromFile(
    "./extra/game/player_1.png", 0);
    list->txtrs[0].sprite = sfSprite_create();
    sfSprite_setTexture(list->txtrs[0].sprite, list->txtrs[0].texture, sfTrue);
    sfSprite_setPosition(list->txtrs[0].sprite, list->txtrs[0].position);
    sfSprite_setTextureRect(list->txtrs[0].sprite, list->txtrs[0].rectangle);
    list->txtrs[1].texture = sfTexture_createFromFile(
    "./extra/game/player_2.png", 0);
    list->txtrs[1].sprite = sfSprite_create();
    sfSprite_setTexture(list->txtrs[1].sprite, list->txtrs[1].texture, sfTrue);
    sfSprite_setPosition(list->txtrs[1].sprite, list->txtrs[1].position);
    sfSprite_setTextureRect(list->txtrs[1].sprite, list->txtrs[1].rectangle);
}

static void background(window_t *main, texture_t *texture)
{
    texture->texture = sfTexture_createFromFile(main->background, NULL);
    texture->sprite = sfSprite_create();
    sfSprite_setTexture(texture->sprite, texture->texture, sfFalse);
    sfRenderWindow_drawSprite(main->window, texture->sprite, NULL);
    sfSprite_destroy(texture->sprite);
    sfTexture_destroy(texture->texture);
    if (main->music_bool == sfFalse)
        music(main);
}

void start_game(window_t *main, button_t *button, texture_t *texture,
    list_t *list)
{
    sfTime time1;
    sfTime time2;
    float t1 = 0;
    float t2 = 0;

    switch_option(main);
    background(main, texture);
    make_players(list);
    draw_sprite(main, list);
    time1 = sfClock_getElapsedTime(list->txtrs[0].clock);
    time2 = sfClock_getElapsedTime(list->txtrs[1].clock);
    t1 = sfTime_asSeconds(time1);
    t2 = sfTime_asSeconds(time2);
    player_conditions_1(t1, main, list);
    player_conditions_2(t2, main, list);
    if (t1 > 0.3)
        list->txtrs[0].rectangle.left = 0;
    if (t2 > 0.3)
        list->txtrs[1].rectangle.left = 0;
    destroy_sprite(list);
}
