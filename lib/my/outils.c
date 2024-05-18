/*
** EPITECH PROJECT, 2023
** GAME-JAM
** File description:
** outils.c
*/

#include "my.h"

void music(window_t *main)
{
    main->music = sfMusic_createFromFile(main->sound_select);
    sfMusic_setLoop(main->music, sfTrue);
    sfMusic_setVolume(main->music, 10);
    sfMusic_play(main->music);
    main->music_bool = sfTrue;
}

sfBool left_click_released(sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft)
        return sfTrue;
    else
        return sfFalse;
}
