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

static void init_main(window_t *main)
{
    main->mode.width = 1920;
    main->mode.height = 1080;
    main->mode.bitsPerPixel = 32;
    main->window = sfRenderWindow_create(main->mode, "Brasier En Duel",
    sfClose | sfResize, NULL);
    main->menu = sfTrue;
    main->music_bool = sfFalse;
    main->background = "extra/menu/menu.jpg";
    main->sound_select = "extra/sound/menu.ogg";
    main->font = "extra/font/font.ttf";
    main->sett_logo = "extra/menu/setting_logo.png";
    main->map_chose = 10;
    main->time_chose = 10;
    main->selection = sfFalse;
}

static void init_game(list_t *list)
{
    list->txtrs[0].rectangle = (sfIntRect){0, 0, 84, 84};
    list->txtrs[0].position = (sfVector2f){800, 600};
    list->txtrs[0].clock = sfClock_create();
    list->txtrs[1].rectangle = (sfIntRect){0, 0, 84, 84};
    list->txtrs[1].position = (sfVector2f){960, 540};
    list->txtrs[1].clock = sfClock_create();
}

int main(int argc, char **argv)
{
    window_t main;
    list_t list;
    button_t button;
    texture_t texture;

    if (argc != 1)
        return 84;
    init_main(&main);
    init_game(&list);
    while (sfRenderWindow_isOpen(main.window)) {
        event_close(&main);
        sfRenderWindow_clear(main.window, sfTransparent);
        if (main.menu == sfTrue)
            main_menu(&main, &button, &texture);
        if (main.menu == sfFalse) {
            start_game(&main, &button, &texture, &list);
        }
        sfRenderWindow_display(main.window);
    }
    sfRenderWindow_destroy(main.window);
    return 0;
}
