/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** fonction_disp.c
*/

#include "my.h"

void display_text(char *text, window_t *main, button_t *button)
{
    button->text = sfText_create();
    button->font = sfFont_createFromFile("extra/font/Pareidolia.ttf");
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, button->size);
    sfText_setFillColor(button->text, button->color);
    sfText_setString(button->text, text);
    sfText_setPosition(button->text, button->position);
    sfRenderWindow_drawText(main->window, button->text, NULL);
    sfText_destroy(button->text);
    sfFont_destroy(button->font);
}

void display_rectangle(window_t *main, button_t *button, sfColor color)
{
    button->color = color;
    button->button_menu = sfRectangleShape_create();
    sfRectangleShape_setSize(button->button_menu,
    button->size_rec);
    sfRectangleShape_setFillColor(button->button_menu,
    button->color);
    sfRectangleShape_setPosition(button->button_menu,
    button->position);
    sfRenderWindow_drawRectangleShape(main->window,
    button->button_menu, NULL);
    sfRectangleShape_destroy(button->button_menu);
}
