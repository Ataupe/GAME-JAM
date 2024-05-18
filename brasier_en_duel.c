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
    main->scale = (sfVector2f){1, 1};
    main->menu = sfTrue;
    main->music_bool = sfFalse;
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
    while (sfRenderWindow_isOpen(main.window)) {
        event_close(&main);
        sfRenderWindow_clear(main.window, sfTransparent);
        if (main.menu == sfTrue)
            main_menu(&main, &button, &texture);
        if (main.menu == sfFalse) {
            exit(0);
        }
        sfRenderWindow_display(main.window);
    }
    sfRenderWindow_destroy(main.window);
    return 0;
}
