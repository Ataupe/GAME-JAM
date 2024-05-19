/*
** EPITECH PROJECT, 2023
** GAME-JAM
** File description:
** brasier_en_duel.c
*/

#include "my.h"

static void event_close(window_t *main)
{
    while (sfRenderWindow_pollEvent(main->window, &main->event)) {
        if (main->event.type == sfEvtClosed) {
            sfRenderWindow_close(main->window);
        }
    }
}

void init_main(window_t *main)
{
    main->mode.width = 1920;
    main->mode.height = 1080;
    main->mode.bitsPerPixel = 32;
    main->menu = sfTrue;
    main->music_bool = sfFalse;
    main->exit_game_menu = sfFalse;
    main->pause_menu = sfFalse;
    main->end_of_game = sfFalse;
    main->background = "extra/menu/menu.jpg";
    main->sound_select = "extra/sound/menu.ogg";
    main->font = "extra/font/font.ttf";
    main->sett_logo = "extra/menu/setting_logo.png";
    main->map_chose = 10;
    main->time_chose = 10;
    main->selection = sfFalse;
}

void init_game(list_t *list)
{
    list->txtrs[0].rectangle = (sfIntRect){0, 0, 50, 50};
    list->txtrs[0].position = (sfVector2f){800, 600};
    list->txtrs[0].clock = sfClock_create();
    list->txtrs[1].rectangle = (sfIntRect){0, 0, 50, 50};
    list->txtrs[1].position = (sfVector2f){960, 540};
    list->txtrs[1].clock = sfClock_create();
    list->txtrs[2].rectangle = (sfIntRect){0, 0, 166, 166};
    list->txtrs[2].position = (sfVector2f){10, 10};
    list->txtrs[2].clock = sfClock_create();
    list->txtrs[3].rectangle = (sfIntRect){0, 0, 166, 166};
    list->txtrs[3].position = (sfVector2f){93, 10};
    list->txtrs[3].clock = sfClock_create();
    list->txtrs[4].clock = sfClock_create();
    list->txtrs[4].countdown = 31;
    list->txtrs[5].clock = sfClock_create();
    list->txtrs[5].countdown = 61;
    list->txtrs[6].clock = sfClock_create();
    list->txtrs[6].countdown = 91;
}

int main(int argc, char **argv)
{
    window_t main;
    list_t list;
    button_t button;
    texture_t texture;

    init_main(&main);
    init_game(&list);
    main.window = sfRenderWindow_create(main.mode, "BrasierEnDuel", 4 | 2, 0);
    while (sfRenderWindow_isOpen(main.window)) {
        event_close(&main);
        sfRenderWindow_clear(main.window, sfTransparent);
        if (main.menu == sfTrue)
            main_menu(&main, &button, &texture);
        if (main.menu == sfFalse)
            start_game(&main, &button, &texture, &list);
        sfRenderWindow_display(main.window);
    }
    sfRenderWindow_destroy(main.window);
    return 0;
}
