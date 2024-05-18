/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** structures.h
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

typedef struct texture_s {
    sfImage* image;
    sfSprite* sprite;
    sfTexture* texture;
    sfIntRect rectangle;
    sfClock* clock;
    sfClock* clock2;
    sfVector2f position;
} texture_t;

typedef struct button_s {
    int size;
    sfText *text;
    sfFont* font;
    sfRectangleShape *button_menu;
    sfColor color;
    sfVector2f position;
    sfVector2f size_rec;
} button_t;

typedef struct list_s {
    texture_t txtrs[2];
} list_t;

typedef struct window_s {
    sfRenderWindow* window;
    sfVideoMode mode;
    sfVector2f scale;
    sfEvent event;
    sfBool menu;
    sfBool music_bool;
    sfMusic *music;
    sfBool setting_bool;
} window_t;

#endif /* STRUCTURES_H_ */
