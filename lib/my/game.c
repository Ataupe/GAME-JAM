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

static void draw_destroy_sprite(window_t *main, list_t *list)
{
    sfRenderWindow_drawSprite(main->window, list->txtrs[0].sprite, NULL);
    sfRenderWindow_drawSprite(main->window, list->txtrs[1].sprite, NULL);
    sfRenderWindow_drawSprite(main->window, list->txtrs[2].sprite, NULL);
    sfRenderWindow_drawSprite(main->window, list->txtrs[3].sprite, NULL);
    sfSprite_destroy(list->txtrs[0].sprite);
    sfTexture_destroy(list->txtrs[0].texture);
    sfSprite_destroy(list->txtrs[1].sprite);
    sfTexture_destroy(list->txtrs[1].texture);
    sfSprite_destroy(list->txtrs[2].sprite);
    sfTexture_destroy(list->txtrs[2].texture);
    sfSprite_destroy(list->txtrs[3].sprite);
    sfTexture_destroy(list->txtrs[3].texture);
}

static void movement_players(window_t *main, list_t *list)
{
    sfTime time1;
    sfTime time2;
    float t1 = 0;
    float t2 = 0;

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
}

static void event_button3(window_t *main, list_t *list, button_t *button)
{
    char *chose[2] = {"OUI", "NON"};
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    if (main->exit_game_menu == sfTrue) {
        button->position = (sfVector2f){830, 510};
        button->color = sfBlack;
        button->size = 20;
        display_text("Quitter la partie ?", main, button);
        button->position = (sfVector2f){900, 550};
        button->size = 15;
        if (mousePos.x >= 900 && mousePos.x <= 1000 && mousePos.y >= 550 &&
        mousePos.y <= 560)
            button->color = sfColor_fromRGB(220, 75, 0);
        for (int i = 0; i != 2; i++) {
            display_text(chose[i], main, button);
            button->position.x += 50;
        }
    }
}

static void event_button2(window_t *main, list_t *list, button_t *button)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    if (main->pause_menu == sfTrue) {
        list->txtrs[3].rectangle.top = 166;
        list->txtrs[3].position = (sfVector2f){186, 8};
        if (left_click_released(main->event) && mousePos.x >= 186 &&
        mousePos.x <= 269 && mousePos.y >= 10 && mousePos.y <= 83) {
            main->pause_menu = sfFalse;
            list->txtrs[3].rectangle.top = 332;
            list->txtrs[3].position = (sfVector2f){96, 10};
            sfMusic_play(main->music);
        }
    }
    event_button3(main, list, button);
}

static void event_button(window_t *main, list_t *list, button_t *button)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    if (left_click_released(main->event) && mousePos.x >= 10 &&
    mousePos.x <= 83 && mousePos.y >= 10 && mousePos.y <= 83)
        main->exit_game_menu = sfTrue;
    if (left_click_released(main->event) && mousePos.x >= 93 &&
    mousePos.x <= 176 && mousePos.y >= 10 && mousePos.y <= 83)
        main->pause_menu = sfTrue;
    if (main->exit_game_menu == sfTrue || main->pause_menu == sfTrue)
        sfMusic_pause(main->music);
    if (main->exit_game_menu == sfTrue) {
        button->size_rec = (sfVector2f){300, 100};
        button->position = (sfVector2f){810, 490};
        display_rectangle(main, button, sfColor_fromRGBA(255, 255, 255, 210));
        if (left_click_released(main->event) && mousePos.x >= 940 &&
        mousePos.x <= 1000 && mousePos.y >= 550 && mousePos.y <= 560) {
            main->exit_game_menu = sfFalse;
            sfMusic_play(main->music);
        }
    }
}

static void make_button(list_t *list)
{
    list->txtrs[2].texture = sfTexture_createFromFile(
    "./extra/game/button.png", 0);
    list->txtrs[2].sprite = sfSprite_create();
    sfSprite_scale(list->txtrs[2].sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setTexture(list->txtrs[2].sprite, list->txtrs[2].texture, sfTrue);
    sfSprite_setPosition(list->txtrs[2].sprite, list->txtrs[2].position);
    sfSprite_setTextureRect(list->txtrs[2].sprite, list->txtrs[2].rectangle);
    list->txtrs[2].rectangle.top = 332;
    list->txtrs[3].texture = sfTexture_createFromFile(
    "./extra/game/button.png", 0);
    list->txtrs[3].sprite = sfSprite_create();
    sfSprite_scale(list->txtrs[3].sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setTexture(list->txtrs[3].sprite, list->txtrs[3].texture, sfTrue);
    sfSprite_setPosition(list->txtrs[3].sprite, list->txtrs[3].position);
    sfSprite_setTextureRect(list->txtrs[3].sprite, list->txtrs[3].rectangle);
    list->txtrs[3].rectangle.top = 332;
    list->txtrs[3].rectangle.left = 166;
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
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    switch_option(main);
    if (main->end_of_game == sfTrue) {
        return;
    }
    background(main, texture);
    make_players(list);
    make_button(list);
    draw_destroy_sprite(main, list);
    event_button(main, list, button);
    event_button2(main, list, button);
    game2(main, button, texture, list);
    if (main->exit_game_menu == sfTrue || main->pause_menu == sfTrue) {
        return;
    }
    movement_players(main, list);
}
