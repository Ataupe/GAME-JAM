/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <stdarg.h>
    #include <fcntl.h>
    #include <string.h>
    #include "structures.h"

    #define BUFFER_SIZE 1024

void main_menu(window_t *main, button_t *button, texture_t *texture);
void display_text(char *text, window_t *main, button_t *button);
void display_rectangle(window_t *main, button_t *button, sfColor color);
void music(window_t *main);
sfBool left_click_released(sfEvent event);
void start_game(window_t *main, button_t *button, texture_t *texture, list_t *list);
void player_conditions_1(float t, window_t *main, list_t *list);
void player_conditions_2(float t, window_t *main, list_t *list);
void player_animation_up1(float t, window_t *main, list_t *list);
void player_animation_down1(float t, window_t *main, list_t *list);
void player_animation_left1(float t, window_t *main, list_t *list);
void player_animation_right1(float t, window_t *main, list_t *list);
void player_animation_up2(float t, window_t *main, list_t *list);
void player_animation_down2(float t, window_t *main, list_t *list);
void player_animation_left2(float t, window_t *main, list_t *list);
void player_animation_right2(float t, window_t *main, list_t *list);

#endif /* !MY_H_ */
