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

#endif /* !MY_H_ */
