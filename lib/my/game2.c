/*
** EPITECH PROJECT, 2023
** GAME-JAM
** File description:
** game2.c
*/

#include "my.h"

static void destroy_counter(list_t *list)
{
    sfClock_destroy(list->txtrs[4].clock);
    sfClock_destroy(list->txtrs[5].clock);
    sfClock_destroy(list->txtrs[6].clock);
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
    display_text(buffer, main, button);
    if (list->txtrs[i].countdown <= 0)
        main->end_of_game = sfTrue;
}

static void event_button4(window_t *main, list_t *list, button_t *button)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(main->window);

    if (main->exit_game_menu == sfTrue) {
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
    event_button4(main, list, button);
    display_counter(main, button, list);
}
