/*
** EPITECH PROJECT, 2023
** GAME-JAM
** File description:
** game2.c
*/

#include "my.h"

sfBool check_collision(sfSprite *flame, sfSprite *water)
{
    sfVector2f flamme = sfSprite_getPosition(flame);
    sfVector2f eau = sfSprite_getPosition(water);

    if (eau.x >= flamme.x - 32 && eau.x <= flamme.x + 32 && eau.y >= flamme.y - 32 && eau.y <= flamme.y +32)
        return sfTrue;
    return sfFalse;
}

static void destroy_counter(list_t *list)
{
    sfClock_destroy(list->txtrs[4].clock);
    sfClock_destroy(list->txtrs[5].clock);
    sfClock_destroy(list->txtrs[6].clock);
}

static void end_of_the_game_menu3(window_t *main, button_t *button, texture_t *texture,
    list_t *list)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    if (left_click_released(main->event) && mousePos.x >= 920 && mousePos.x <= 1000 && mousePos.y >= 515 && mousePos.y <= 535) {
        main->music_bool = sfFalse;
        main->end_of_game = sfFalse;
        destroy_counter(list);
        init_game(list);
    }
    if (left_click_released(main->event) && mousePos.x >= 870 && mousePos.x <= 1050 && mousePos.y >= 565 && mousePos.y <= 585) {
        destroy_counter(list);
        init_main(main);
        init_game(list);
    }
}

static void end_of_the_game_menu2(window_t *main, button_t *button, texture_t *texture,
    list_t *list)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    button->size = 15;
    button->position = (sfVector2f){920, 525};
    button->color = sfBlack;
    display_text("REJOUER", main, button);
    if (mousePos.x >= 920 && mousePos.x <= 1000 && mousePos.y >= 515 && mousePos.y <= 535) {
        button->color = sfRed;
        display_text("REJOUER", main, button);
    }
    button->color = sfBlack;
    button->position.y += 50;
    button->position.x -= 50;
    display_text("MENU PRINCIPALE", main, button);
    if (mousePos.x >= 870 && mousePos.x <= 1050 && mousePos.y >= 565 && mousePos.y <= 585) {
        button->color = sfRed;
        display_text("MENU PRINCIPALE", main, button);
    }
    end_of_the_game_menu3(main, button, texture, list);
}

void end_of_the_game_menu(window_t *main, button_t *button, texture_t *texture,
    list_t *list)
{
    int i = main->time_chose + 1;

    button->size_rec = (sfVector2f){400, 300};
    button->position = (sfVector2f){760, 390};
    display_rectangle(main, button, sfColor_fromRGBA(255, 255, 255, 230));
    button->size = 15;
    button->position = (sfVector2f){770, 450};
    button->color = sfColor_fromRGB(80, 150, 235);
    if (list->txtrs[i].countdown <= 10)
        button->color = sfColor_fromRGB(250, 100, 10);
    if (list->txtrs[i].countdown != 0) {
        display_text("LA FLAMME OLYMPIQUE S'EST ETEINTE.", main, button);
    } else {
        button->size = 14;
        display_text("LA FLAMME OLYPIQUE BRULE TOUJOURS !", main, button);
    }
    end_of_the_game_menu2(main, button, texture, list);

}

static void display_counter(window_t *main, button_t *button, list_t *list)
{
    char buffer[8] = {"PAUSE"};
    int i = main->time_chose + 1;

    if (main->exit_game_menu == sfFalse && main->pause_menu == sfFalse) {
        list->txtrs[i].elapsed = sfClock_getElapsedTime(list->txtrs[i].clock);
        if (sfTime_asSeconds(list->txtrs[i].elapsed) >= 1.0f) {
            list->txtrs[i].countdown -= 1;
            sfClock_restart(list->txtrs[i].clock);
        }
        snprintf(buffer, sizeof(buffer), "%d", list->txtrs[i].countdown);
    }
    button->size = 30;
    button->position = (sfVector2f){1750, 25};
    button->color = sfWhite;
    if (list->txtrs[i].countdown <= 10)
        button->color = sfRed;
    display_text(buffer, main, button);
    if (list->txtrs[i].countdown <= 0)
        main->end_of_game = sfTrue;
}

static void event_button4(window_t *main, list_t *list, button_t *button)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    if (main->exit_game_menu == sfTrue ) {
        if (left_click_released(main->event) && mousePos.x >= 900 &&
        mousePos.x <= 940 && mousePos.y >= 550 && mousePos.y <= 560) {
            sfMusic_destroy(main->music);
            destroy_counter(list);
            init_main(main);
            init_game(list);
        }
    }
}

void game2(window_t *main, button_t *button, texture_t *texture,
    list_t *list)
{
    int i = main->time_chose + 1;

    sfRenderWindow_drawSprite(main->window, list->txtrs[0].sprite, NULL);
    sfRenderWindow_drawSprite(main->window, list->txtrs[1].sprite, NULL);
    sfRenderWindow_drawSprite(main->window, list->txtrs[2].sprite, NULL);
    sfRenderWindow_drawSprite(main->window, list->txtrs[3].sprite, NULL);
    event_button4(main, list, button);
    if (check_collision(list->txtrs[0].sprite, list->txtrs[1].sprite) ||
    list->txtrs[i].countdown == 0) {
        main->end_of_game = sfTrue;
        sfMusic_destroy(main->music);
    }
    display_counter(main, button, list);
}
