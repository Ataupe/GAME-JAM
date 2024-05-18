/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_menu.c
*/

#include "my.h"


static void music(window_t *main)
{
    main->music = sfMusic_createFromFile("extra/sound/menu.ogg");
    sfMusic_setLoop(main->music, sfTrue);
    sfMusic_setVolume(main->music, 10);
    sfMusic_play(main->music);
    main->music_bool = sfTrue;
}

static void button_menu(window_t *main, button_t *button)
{
    button->position = (sfVector2f){650, 350};
    button->color = sfWhite;
    button->size = 70;
    display_text("Start", main, button);
}

static void title(window_t *main, button_t *button)
{
    button->position = (sfVector2f){500, 100};
    button->color = sfWhite;
    button->size = 100;
    display_text("Brasier En Duel", main, button);
}

static void background(window_t *main, texture_t *texture)
{
    texture->image = sfImage_createFromFile("extra/menu/menu.jpg");
    texture->texture = sfTexture_createFromImage(texture->image,
    NULL);
    texture->sprite = sfSprite_create();
    sfSprite_scale(texture->sprite, main->scale);
    sfSprite_setTexture(texture->sprite, texture->texture,
    sfFalse);
    sfRenderWindow_drawSprite(main->window, texture->sprite, NULL);
    sfImage_destroy(texture->image);
    sfSprite_destroy(texture->sprite);
    sfTexture_destroy(texture->texture);
}

void main_menu(window_t *main, button_t *button, texture_t *texture)
{
    if (main->music_bool == sfFalse)
        music(main);
    background(main, texture);
    title(main, button);
    button_menu(main, button);
    if (main->setting_bool == sfTrue) {
        return;
    }
}

//setting(main, list, button);
//event_button(main, list, button);
//event(main, list);
//destroy()
