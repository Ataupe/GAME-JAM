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

void start_game(window_t *main, button_t *button, texture_t *texture)
{
    switch_option(main);
    background(main, texture);
}

//sfTime time;
//float t = 0;
//
//if (main->music_bool == sfFalse)
//    music(main);
//make(list);
//draw_sprite(main, list);
//time = sfClock_getElapsedTime(list->txtrs[1].clock);
//t = sfTime_asSeconds(time);
//player_conditions(t, main, list);
//if (t > 0.3)
//    list->txtrs[1].rectangle.left = 0;
//destroy_sprite(list);
