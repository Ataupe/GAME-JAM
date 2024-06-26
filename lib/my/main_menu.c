/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_menu.c
*/

#include "my.h"

static void selection(int index, window_t *main)
{
    if (index >= 0 && index <= 2)
        main->map_chose = index;
    if (index >= 3 && index <= 5)
        main->time_chose = index;
    if (main->map_chose != 10 && main->time_chose != 10)
        main->selection = sfTrue;
}

static void event_start_game(window_t *main, button_t *button)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    button->color = sfWhite;
    if (main->selection == sfTrue) {
        button->position = (sfVector2f){1300, 710};
        button->size = 30;
        if (mousePos.x >= 1300 && mousePos.x <= 1740 && mousePos.y >= 700 &&
            mousePos.y <= 740)
            button->color = sfColor_fromRGB(220, 75, 0);
        display_text("Commencer la Partie", main, button);
        if (left_click_released(main->event) && mousePos.x >= 1300 &&
        mousePos.x <= 1740 && mousePos.y >= 700 && mousePos.y <= 740) {
            main->menu = sfFalse;
            sfMusic_destroy(main->music);
            main->music_bool = sfFalse;
        }
    }
}

static void on_selection(window_t *main, button_t *button, int index,
    sfVector2f pos)
{
    char *text[6] = {"MAP 1", "MAP 2", "MAP 3", "30 sec", "60 sec",
    "90 sec"};
    sfColor color = sfColor_fromRGB(220, 75, 0);

    button->font = sfFont_createFromFile(main->font);
    button->text = sfText_create();
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, text[index]);
    sfText_setCharacterSize(button->text, 18);
    sfText_setPosition(button->text, pos);
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        selection(index, main);
    }
    sfText_setFillColor(button->text, color);
    sfRenderWindow_drawText(main->window, button->text, NULL);
    sfText_destroy(button->text);
    sfFont_destroy(button->font);
}

static void event_button2(window_t *main, button_t *button)
{
    if (main->map_chose == 0)
        on_selection(main, button, 0, (sfVector2f){110, 455});
    if (main->map_chose == 1)
        on_selection(main, button, 1, (sfVector2f){260, 455});
    if (main->map_chose == 2)
        on_selection(main, button, 2, (sfVector2f){410, 455});
    if (main->time_chose == 3)
        on_selection(main, button, 3, (sfVector2f){110, 655});
    if (main->time_chose == 4)
        on_selection(main, button, 4, (sfVector2f){255, 655});
    if (main->time_chose == 5)
        on_selection(main, button, 5, (sfVector2f){400, 655});
}

static void event_button(window_t *main, button_t *button)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    if (mousePos.x >= 100 && mousePos.x <= 200 && mousePos.y >= 440 &&
    mousePos.y <= 490)
        on_selection(main, button, 0, (sfVector2f){110, 455});
    if (mousePos.x >= 245 && mousePos.x <= 345 && mousePos.y >= 440 &&
    mousePos.y <= 490)
        on_selection(main, button, 1, (sfVector2f){260, 455});
    if (mousePos.x >= 390 && mousePos.x <= 490 && mousePos.y >= 440 &&
    mousePos.y <= 490)
        on_selection(main, button, 2, (sfVector2f){410, 455});
    if (mousePos.x >= 100 && mousePos.x <= 200 && mousePos.y >= 640 &&
    mousePos.y <= 690)
        on_selection(main, button, 3, (sfVector2f){110, 655});
    if (mousePos.x >= 245 && mousePos.x <= 345 && mousePos.y >= 640 &&
    mousePos.y <= 690)
        on_selection(main, button, 4, (sfVector2f){255, 655});
    if (mousePos.x >= 390 && mousePos.x <= 490 && mousePos.y >= 640 &&
    mousePos.y <= 690)
        on_selection(main, button, 5, (sfVector2f){400, 655});
}

static void info_du_jeu(window_t *main, button_t *button)
{
    button->position = (sfVector2f){1400, 100};
    button->color = sfColor_fromRGBA(255, 255, 255, 240);
    button->size = 18;
    display_text("Brasier en Duel est un jeu competitif\n"
        "   en 1 contre 1 ou l'objectif est de\n"
        "sauver la flamme olympique. Le joueur\n"
        "      1 (rouge) doit eviter le joueur\n"
        "  2 (bleu). Chaque joueur choisit son\n"
        "element et se lance dans une bataille\n"
        "    strategique en un lapse de temps.\n", main, button);
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
    char *taille[3] = {"MAP 1", "MAP 2", "MAP 3"};

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
    button->position = (sfVector2f){110, 455};
    button->size = 18;
    for (int i = 0; i != 3; i++) {
        display_text(taille[i], main, button);
        button->position.x += 150;
    }
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

void main_menu(window_t *main, button_t *button, texture_t *texture)
{
    background(main, texture);
    button_menu(main, button);
    texts_menu(main, button);
    info_du_jeu(main, button);
    event_button(main, button);
    event_button2(main, button);
    event_start_game(main, button);
}
