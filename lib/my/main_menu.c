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
    char *duree[3] = {"30 sec", "60 sec", "90 sec"};

    button->size_rec = (sfVector2f){100, 50};
    button->position = (sfVector2f){100, 440};
    for (int i = 0; i != 3; i++) {
        display_rectangle(main, button, sfColor_fromRGBA(255, 255, 255, 230));
        button->position.x += 145;
    }
    button->position = (sfVector2f){100, 640};
    for (int i = 0; i != 3; i++) {
        display_rectangle(main, button, sfColor_fromRGBA(255, 255, 255, 230));
        button->position.x += 145;
    }
    button->color = sfBlack;
    button->position = (sfVector2f){110, 655};
    button->size = 18;
    for (int i = 0; i != 3; i++) {
        display_text(duree[i], main, button);
        button->position.x += 145;
    }
}

static void texts_menu(window_t *main, button_t *button)
{
    char *texts[2] = {"Taille de la map", "Duree du jeu"};
    char *taille[3] = {"10 X 10", "15 X 15", "20 X 20"};

    button->position = (sfVector2f){100, 100};
    button->color = sfColor_fromRGBA(255, 255, 255, 240);
    button->size = 70;
    display_text("Brasier En Duel", main, button);
    button->position = (sfVector2f){100, 350};
    button->size = 40;
    for (int i = 0; i != 2; i++) {
        display_text(texts[i], main, button);
        button->position.y += 200;
    }
    button->color = sfBlack;
    button->position = (sfVector2f){106, 455};
    button->size = 18;
    for (int i = 0; i != 3; i++) {
        display_text(taille[i], main, button);
        button->position.x += 145;
    }
}

static void background(window_t *main, texture_t *texture)
{
    texture->texture = sfTexture_createFromFile(main->bck_menu, NULL);
    texture->sprite = sfSprite_create();
    sfSprite_scale(texture->sprite, main->scale);
    sfSprite_setTexture(texture->sprite, texture->texture, sfFalse);
    sfRenderWindow_drawSprite(main->window, texture->sprite, NULL);
    sfSprite_destroy(texture->sprite);
    sfTexture_destroy(texture->texture);
    texture->texture = sfTexture_createFromFile(main->sett_logo, NULL);
    texture->sprite = sfSprite_create();
    sfSprite_setTexture(texture->sprite, texture->texture, sfFalse);
    sfSprite_setPosition(texture->sprite,
    (sfVector2f){1850 * main->size, 950 * main->size});
    sfRenderWindow_drawSprite(main->window, texture->sprite, NULL);
    sfSprite_destroy(texture->sprite);
    sfTexture_destroy(texture->texture);
}

void main_menu(window_t *main, button_t *button, texture_t *texture)
{
    if (main->music_bool == sfFalse)
        music(main);
    background(main, texture);
    button_menu(main, button);
    texts_menu(main, button);
}

//if (main->setting_bool == sfTrue) {
//    return;
//}
//event_button(main, button, button);
//event(main, button);
//destroy()
