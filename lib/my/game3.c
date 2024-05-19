/*
** EPITECH PROJECT, 2023
** GAMEJAM
** File description:
** game3.c
*/

#include "my.h"
#include "structures.h"

bool check_collision(sfSprite *flame, sfSprite *water)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(flame);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(water);

    return sfFloatRect_intersects(&rect1, &rect2, NULL);
}

//if (check_collision(/*nom du sprite de feu*/, /*nom du sprite de l'eau*/))
//{
//    water_end_game();
//}

//ZOLTAN T'AURAS JUSTE A INCLURE CETTE CONDITION OU TU VEUX POUR QUE CA CHECK LES COLLISIONS
